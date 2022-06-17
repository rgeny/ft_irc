/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/17 19:23:33 by abesombe         ###   ########.fr       */
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

void Command::reset_access_control_data(void)
{
	_chan_user_list = NULL;
	_chan_invite_list = NULL;
	_chan_ban_list = NULL;
	_is_on_guestlist = false;
	_is_above_chan_limit = false;
}

void Command::init_access_control_data(void)
{
	Channel *cur_chan = (*this->_chans_it).second;
	_is_key_set = cur_chan->get_specific_mode(CHANMODE_k);
	_is_limit_set = cur_chan->get_specific_mode(CHANMODE_l);
	_inviteonly_set = cur_chan->get_specific_mode(CHANMODE_i);
	_chan_ban_list = &cur_chan->get_chan_ban_list();
	_is_on_ban_list = (_chan_ban_list->find((*_users_it)->get_nickname()) != _chan_ban_list->end());
	_chan_user_list = &cur_chan->get_chan_user_list();
	_is_above_chan_limit = (cur_chan->get_limit() < _chan_user_list->size() + 1);
	_current_key = cur_chan->get_key();
}

void Command::set_new_channel(String chan_name)
{
	Channel *cur_chan = NULL;
	this->_chans[chan_name] = new Channel(chan_name, "");
	_chans_it = this->_chans.find(chan_name);
	// By Default, new channels are created with mode +nt
	cur_chan = (*this->_chans_it).second;
	cur_chan->set_specific_mode(CHANMODE_n, true);
	cur_chan->set_specific_mode(CHANMODE_t, true);	
	// Current user who creates a brand new channel is automatically promoted to chan op status
	(*_users_it)->set_chan_usermode(cur_chan->get_chan_name(), USERMODE_o, true);	
	// ADD USER TO CHAN_USER_LIST
}

int  Command::join_process(String chan_name)
{
	Channel *cur_chan = NULL;
	reset_access_control_data();
	this->_chans_it = this->_chans.find(chan_name);

	if (this->_chans_it == _chans.end())
	{
		set_new_channel(chan_name);
		(*_users_it)->set_last_joined_chan(chan_name);
	}
	else 
	{
		init_access_control_data();
		cur_chan = (*this->_chans_it).second;
		String cur_chan_name = cur_chan->get_chan_name();
		_chan_invite_list = &cur_chan->get_chan_invite_list();
		_is_on_guestlist = (_chan_invite_list->find((*_users_it)->get_nickname()) != _chan_invite_list->end());
		// std::cout << "_is_limit_set? " << _is_limit_set << " - and limit nb = " << cur_chan->get_limit() << std::endl;
		// std::cout << "_is_above_chan_limit? " << _is_above_chan_limit << std::endl;
		// std::cout << "_is_on_guestlist? " << _is_on_guestlist << std::endl;
		if (_is_on_guestlist)
		{
			(*_users_it)->set_chan_usermode(cur_chan_name, USERMODE_o, false);
			(*_chan_invite_list).erase((*_users_it)->get_nickname());
			(*_users_it)->set_last_joined_chan(cur_chan_name);
		}
		else if (_is_on_guestlist == false)
		{
			if (_is_key_set && _current_key != _cmd[2])
			{
				return (_err_badchannelkey());
			}
			else if ((_is_key_set && _current_key == _cmd[2]) || !_is_key_set)
			{
				if (_inviteonly_set && !_is_on_guestlist)
					return (_err_inviteonlychan());
				if (_is_limit_set && _is_above_chan_limit && !_is_on_guestlist)
					return (_err_channelisfull());
				if (_is_on_ban_list)
					return (_err_bannedfromchan());
				(*_users_it)->set_chan_usermode(cur_chan_name, USERMODE_o, false);
				(*_users_it)->set_last_joined_chan(cur_chan_name);
			}
		}
	}
	cur_chan = (*this->_chans_it).second;
	_chan_user_list = &(cur_chan->get_chan_user_list());
	(*_chan_user_list)[(*_users_it)->get_nickname()] = *_users_it;
	// std::cout << "Last joined channel = " << (*_users_it)->get_last_joined_chan() << std::endl;

	return (SUCCESS);
}

e_error	Command::_join	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams(_cmd[0]));
	else
	{
		if (_cmd[1] == "0")
		{
			leave_all();
		}
		else
		{
			_user_already_in_channel = false;
			int pwd_index = 0;

			_chan_list = split(this->_cmd[1], ",");
			if (_cmd.size() > 2)
				_password_list = split(this->_cmd[2], ",");
			for (std::vector<String>::iterator it = _chan_list.begin(), ite = _chan_list.end(); it != ite; it++)
			{
				if (_cmd.size() > 2)
					_cmd[2] = _password_list[pwd_index];
				_chan_usermode = (*_users_it)->get_chan_usermode();
				if (_chan_usermode.find(*it) != _chan_usermode.end())
					_user_already_in_channel = true;
				else
					_user_already_in_channel = false;
				_flag_badchanmask = false;
				_cmd[1] = *it;	
				if (check_chan_name(this->_cmd[1]) == false)
				{	
					if (_chan_list.size() == 1 || it == ite - 1)
						return (_err_badchanmask());
					else
					{
						_err_badchanmask();
						_flag_badchanmask = true;
					}
				}
				if (_user_already_in_channel == false \
					&& join_process(_cmd[1]) != ERROR_CONTINUE \
					&& _flag_badchanmask == false)
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
