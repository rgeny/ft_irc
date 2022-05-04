/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:56:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/04 12:23:00 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_mode	(void) const
{
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
									+ "!" + (*_users_it)->get_username()
									+ "@"
									+ this->_hostname, 
									this->_cmd[0] 
									+ " " 
									+ this->_cmd[1], _cmd[2])
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	
	return (SUCCESS);
}