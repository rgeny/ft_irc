/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nosuchnick.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:21:35 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/29 18:21:58 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_nosuchnick	(void) const
{
	String	msg	= this->_set_reply_base (ERR_NOSUCHNICK)
				+ this->_cmd[1]
				+ " :No such nick\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
