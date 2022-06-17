/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_keyset.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:43:16 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/17 18:43:57 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_keyset	(void) const
{
	String	msg	= this->_set_reply_base (ERR_KEYSET)
				+ this->_cmd[1]
				+ " :Channel key already set\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
