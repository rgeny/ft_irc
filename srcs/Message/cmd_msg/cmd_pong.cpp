/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pong.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 18:16:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_pong	(void) const
{
	std::string	msg	= this->_set_msg_base (PONG)
					+ this->_servername
					+ " "
					+ (*this->_msgs_it)[1]
					+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
