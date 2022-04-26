/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 19:21:29 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_join	(void) const
{
	std::string	msg	= this->_set_msg_base (JOIN)
					+ this->_servername
					+ " "
					+ (*this->_msgs_it)[1]
					+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
