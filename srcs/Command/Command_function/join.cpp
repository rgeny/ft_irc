/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 10:30:37 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

/*

A JOIN message may also be sent from the server to indicate that someone has joined a channel. In this case, the <prefix> indicates the user that’s joined. If a user’s JOIN command is successful, they receive one of these messages. In addition, all other clients also receive a JOIN message. For example, if dan and alice are on the channel #toast, and barry joins #toast, then dan and alice will receive a JOIN message indicating that barry has joined the channel.

Whether or not the join request succeeds depends on the channel modes currently set. The key, client limit, ban/exemption, invite-only/exemption, and other channel modes can prevent clients from joining a given channel.

If a user’s JOIN command is successful, the server:

Sends them a JOIN message described above.
May send a MODE message with the current channel’s modes.
Sends them RPL_TOPIC and RPL_TOPICTIME numerics if the channel has a topic set (if the topic is not set, the user is sent no numerics).
Sends them one or more RPL_NAMREPLY numerics (which also contain the name of the user that’s joining).
The examples illustrate some full channel join bursts.

C  ->  JOIN #test
S <-   :dan!~d@0::1 JOIN #test
S <-   :irc.example.com MODE #test +nt
S <-   :irc.example.com 353 dan = #test :@dan
S <-   :irc.example.com 366 dan #test :End of /NAMES list.
*/

int  Command::join_process(String chan_name)
{
	Channel::CHAN_USER_LIST *tmp = NULL;
	Channel::CHAN_INVITE_LIST *chan_invite_list = NULL;
	bool is_key_set;
	bool is_limit_set;
	bool inviteonly_set;
	this->_chans_it = this->_chans.find(chan_name);

	if (this->_chans_it == _chans.end())
	{
		this->_chans[chan_name] = new Channel(chan_name, "");
		_chans_it = this->_chans.find(chan_name);
		(*_chans_it->second).set_specific_mode(CHANMODE_n, true);
		(*_chans_it->second).set_specific_mode(CHANMODE_t, true);	
		(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, true);	
		// (*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), 2);
		// ADD USER TO CHAN_USER_LIST

	}
	else 
	{
		is_key_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_k);
		is_limit_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_l);
		inviteonly_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_i);
		
		if (!is_key_set)
		{
			tmp = &(*_chans_it).second->get_chan_user_list();
			chan_invite_list = &(*_chans_it).second->get_chan_invite_list();
			if (is_limit_set && (*this->_chans_it).second->get_limit() < tmp->size() + 1)
				return (_err_channelisfull());
			if (inviteonly_set && chan_invite_list->find((*_users_it)->get_nickname()) != chan_invite_list->end())
			{
				std::cout << "Je set le nouveau user en regular user" << std::endl;
				(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, false);
				(*chan_invite_list).erase((*_users_it)->get_nickname());
			}
			else if (inviteonly_set && chan_invite_list->find((*_users_it)->get_nickname()) == chan_invite_list->end())
			{
				return (_err_inviteonlychan());
			}
		}
		else if ((*this->_chans_it).second->get_key() == _cmd[2])
		{
			(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, false);
		}
		else if ((*this->_chans_it).second->get_key() != _cmd[2])
			return (_err_badchannelkey());
		// ADD USER TO CHAN_USER_LIST
	}
	tmp = &(*_chans_it).second->get_chan_user_list();
	(*tmp)[(*_users_it)->get_nickname()] = *_users_it;

	return (SUCCESS);
}

// USER => usermode(i, w,)
// 	 => chan_usermode MAP<chan_name, MODE_VEC>
// 	 <#aa, <0,1,0,0,1,0,1,0,0> > chan_usermode[#aa] = MODE_VEC;
// 	 <#bb, <1,0,1,0,0,0,0,0,0> >

e_error	Command::_join	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		if (_cmd[1] == "#0")
		{
			leave_all();
		}
		else
		{
			std::vector<String> chan_list;
			std::vector<String> password_list;

			chan_list = split(this->_cmd[1], ",");
			if (_cmd.size() > 2)
				password_list = split(this->_cmd[2], ",");
			if (chan_list.size() == 1)
			{
				if (check_chan_name(this->_cmd[1]) == false || check_chan_name(this->_cmd[1]) == false)
					return (ERROR_CONTINUE);
				if (join_process(_cmd[1]) != ERROR_CONTINUE)
					return (this->_cmd_join());
			}
			else if (chan_list.size() > 1)
			{
				for (std::vector<String>::iterator it = chan_list.begin(), ite = chan_list.end(); it != ite; it++)
				{
					_cmd[1] = *it;	
					if (check_chan_name(this->_cmd[1]) == false || check_chan_name(this->_cmd[1]) == false)
						return (ERROR_CONTINUE);
					join_process(_cmd[1]);
					if (it != ite - 1)
						this->_cmd_join();
					else
						return (this->_cmd_join());
				}
			}
		}
	}
	return (SUCCESS);
}
