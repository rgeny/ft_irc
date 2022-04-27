/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nicknameinuse.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:47:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:33:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_nicknameinuse	(void) const
{
	String	msg = this->_set_reply_base(ERR_NICKNAMEINUSE)
				+ (*this->_msgs_it)[1]
				+ " :Nickname is already in use\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
