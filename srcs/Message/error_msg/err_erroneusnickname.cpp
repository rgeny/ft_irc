/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_erroneusnickname.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:22:17 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 06:01:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_erroneusnickname	(void) const
{
	String	msg	= this->_set_reply_base (ERR_ERRONEUSNICKNAME)
				+ this->_cmd[1]
				+ " :Erroneus nickname\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
