/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_noprivileges.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:05:00 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/04 13:19:17 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_noprivileges	(String reason) const
{
	String	msg	= this->_set_reply_base (ERR_NOPRIVILEGES)
				+ this->_cmd[1]
				+ " :"
                + reason
                + "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
