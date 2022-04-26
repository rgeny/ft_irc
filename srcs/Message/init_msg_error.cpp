/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msg_error.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:23:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 17:29:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

void	Message::_init_msg_error	(void)
{
	if (this->_msg_error.empty())
	{
		this->_msg_error[ERROR_BAD_PASSWD] = "(Bad Password)\r\n";
		this->_msg_error[ERROR_CLIENT_EXITED] = "(Client Exited)\r\n";
		this->_msg_error[ERROR_SERVER_EXITED] = "(Server Exited)\r\n";
//		this->_msg_error[ERROR_KILL] =;
//		this->_msg_error[ERROR_PING_REPLY] =
//		this->_msg_error[ERROR_PING_TIMEOUT] =
//		this->_msg_error[ERROR_REGITRATION_TIMEOUT] =
	}
}
