/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:31:10 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_join	(void) const
{
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname() + "!" + (*_users_it)->get_username() + "@" + this->_hostname, JOIN, ":" + (*this->_msgs_it)[1])
					+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
