/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_topic_request.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:23:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/01 16:22:24 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_topic_request	(void) const
{
	String	msg	= this->_set_msg_base(this->_hostname, "332 " + (*this->_users_it)->get_nickname() + " " + this->_cmd[1]
						, 
						(*_chans_it).second->get_topic())
						+ "\r\n";
		(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
