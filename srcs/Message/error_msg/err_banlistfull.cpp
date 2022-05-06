/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_banlistfull.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:30:51 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 13:26:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_banlistfull	(void) const
{
	String	msg	= this->_set_reply_base (ERR_BANLISTFULL)
				+ _cmd[1] + " :Channel ban list is full\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}

