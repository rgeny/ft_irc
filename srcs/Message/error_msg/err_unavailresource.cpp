/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_unavailresource.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:06:49 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 17:59:48 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_unavailresource	(void) const
{
	std::string	msg	= this->_set_reply_base(ERR_UNAVAILRESOURCE)
					+ (*this->_msgs_it)[1]
					+ " :Nick/channel is temporarily unavailable\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
