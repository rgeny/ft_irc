/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 00:32:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/02 17:22:00 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

/*
 Command: INVITE
	Parameters: <target>{,<target>} <text to be sent>
The PRIVMSG command is used to send private messages between users, as well as to send messages to channels. <target> is the nickname of a client or the name of a channel.
*/

e_error	Command::_invite	(void)
{
	_chan_invite_list = NULL;
	String target = _cmd[1];
	String cur_user = (*_users_it)->get_nickname();
	if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams());
	if (this->_user_exist(_cmd[1]) == false)
		return (_err_nosuchnick());
	if (this->_chan_exist(_cmd[2]) == false)
		return (_err_nosuchchannel());  
	_chans_it = _chans.find(_cmd[2]);

	if (is_operator(cur_user, *_chans_it->second) == false)
		return (_err_chanoprivsneeded());
	_chan_invite_list = &(*_chans_it).second->get_chan_invite_list();
	(*_chan_invite_list)[target] = _get_user(target);
	return (_cmd_invite());
}