/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_inviteonlychan.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:22:17 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 01:31:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_inviteonlychan	(void) const
{
	String	msg	= this->_set_reply_base (ERR_ERRONEUSNICKNAME)
				+ this->_cmd[1]
				+ " :Cannot join to channel " + _cmd[2] + " (You must be invited)\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
