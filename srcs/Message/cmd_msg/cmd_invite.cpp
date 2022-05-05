/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_invite.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:09:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 01:32:08 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_invite	(void) const
{
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname() 
									+ "!"
									+ (*_users_it)->get_username()
									+ "@"
									+ (*_users_it)->get_host(), String(INVITE)
                                    + " "
                                    + _cmd[1] 
                                    + " " 
                                    + _cmd[2], 
                                    ": inviting " + _cmd[1] + " to " + _cmd[2])  
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    msg	= this->_set_msg_base((*_users_it)->get_nickname() 
                                        + "!"
                                        + (*_users_it)->get_username()
                                        + "@"
                                        + (*_users_it)->get_host(), String(INVITE)
                                        + " "
                                        + (*_users_it)->get_nickname() 
                                        + " " 
                                        + _cmd[2], 
                                        ": invites you to " + _cmd[2])  
                                        + "\r\n";
	this->_get_user(_cmd[1])->add_to_queue(msg);
	return (SUCCESS);
}