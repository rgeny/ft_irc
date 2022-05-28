/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/28 13:12:42 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "User.hpp"
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
	Channel::CHAN_USER_LIST *chan_user_list = NULL;
	Channel::CHAN_INVITE_LIST *chan_invite_list = NULL;
	Channel::CHAN_BAN_LIST *chan_ban_list = NULL;
	bool is_key_set;
	bool is_limit_set;
	bool inviteonly_set;
	bool is_on_ban_list;
	bool is_on_guestlist = false;
	bool is_above_chan_limit = false;
	this->_chans_it = this->_chans.find(chan_name);

	if (this->_chans_it == _chans.end())
	{
		this->_chans[chan_name] = new Channel(chan_name, "");
		_chans_it = this->_chans.find(chan_name);
		(*_chans_it->second).set_specific_mode(CHANMODE_n, true);
		(*_chans_it->second).set_specific_mode(CHANMODE_t, true);	
		// OPERATOR USER
		(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, true);	
		// ADD USER TO CHAN_USER_LIST

	}
	else 
	{
		is_key_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_k);
		is_limit_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_l);
		inviteonly_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_i);
		chan_ban_list = &(*this->_chans_it).second->get_chan_ban_list();
		is_on_ban_list = (chan_ban_list->find((*_users_it)->get_nickname()) != chan_ban_list->end());
		chan_user_list = &(*_chans_it).second->get_chan_user_list();
		is_above_chan_limit = ((*this->_chans_it).second->get_limit() < chan_user_list->size() + 1);

		std::cout << "is_on_ban_list? " << is_on_ban_list << std::endl;
		
		String current_key = (*this->_chans_it).second->get_key();
		
		if (!is_key_set)
		{
			chan_invite_list = &(*_chans_it).second->get_chan_invite_list();
			is_on_guestlist = (chan_invite_list->find((*_users_it)->get_nickname()) != chan_invite_list->end());
			if (is_limit_set && is_above_chan_limit && !is_on_guestlist)
				return (_err_channelisfull());
			if (inviteonly_set && chan_invite_list->find((*_users_it)->get_nickname()) != chan_invite_list->end())
			{
				// REGULAR USER
				(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, false);
				(*chan_invite_list).erase((*_users_it)->get_nickname());
			}
			else if (inviteonly_set && chan_invite_list->find((*_users_it)->get_nickname()) == chan_invite_list->end())
			{
				return (_err_inviteonlychan());
			}
			else if (is_on_ban_list && chan_invite_list->find((*_users_it)->get_nickname()) != chan_invite_list->end())
			{
				(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, false);
			}
			else if (!inviteonly_set && is_on_ban_list)
			{
				return (_err_bannedfromchan());
			}
			else if (!inviteonly_set && !is_on_ban_list)
			{
				(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, false);
			}
		}
		else if (current_key == _cmd[2])
		{
			std::cout << "Key offered: " << _cmd[2] << " vs real key: " << current_key << std::endl;
			(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), USERMODE_o, false);
		}
		else if (current_key != _cmd[2])
		{
			std::cout << "Key offered: " << _cmd[2] << " vs real key: " << current_key << std::endl;
			return (_err_badchannelkey());
		}
	}
	chan_user_list = &(*_chans_it).second->get_chan_user_list();
	(*chan_user_list)[(*_users_it)->get_nickname()] = *_users_it;

	return (SUCCESS);
}

e_error	Command::_join	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		if (_cmd[1] == "0")
		{
			leave_all();
		}
		else
		{
			std::vector<String> chan_list;
			std::vector<String> password_list;
			User::CHAN_USERMODE chan_usermode;

			bool user_already_in_channel = false;
			bool flag_badchanmask;

			chan_list = split(this->_cmd[1], ",");
			if (_cmd.size() > 2)
				password_list = split(this->_cmd[2], ",");
			int pwd_index = 0;
			for (std::vector<String>::iterator it = chan_list.begin(), ite = chan_list.end(); it != ite; it++)
			{
				if (_cmd.size() > 2)
					_cmd[2] = password_list[pwd_index];
				chan_usermode = (*_users_it)->get_chan_usermode();
				if (chan_usermode.find(*it) != chan_usermode.end())
					user_already_in_channel = true;
				else
					user_already_in_channel = false;
				flag_badchanmask = false;
				_cmd[1] = *it;	
				if (check_chan_name(this->_cmd[1]) == false)
				{	
					if (chan_list.size() == 1 || it == ite - 1)
						return (_err_badchanmask());
					else
					{
						_err_badchanmask();
						flag_badchanmask = true;
					}
				}
				if (user_already_in_channel == false \
					&& join_process(_cmd[1]) != ERROR_CONTINUE \
					&& flag_badchanmask == false)
				{
					if (it != ite - 1)
						this->_cmd_join();
					else
						return (this->_cmd_join());
				}
				pwd_index++;
			}
		}
	}
	return (SUCCESS);
}
