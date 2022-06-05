/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_useronchannel.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:16:59 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/05 11:42:11 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_useronchannel	(void) const
{
	String	msg	= this->_set_reply_base (ERR_USERONCHANNEL)
				+ this->_cmd[1]
                + " "
                + this->_cmd[2]
				+ " :is already on channel\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
