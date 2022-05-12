/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_badchanmask.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:22:17 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/12 13:15:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_badchanmask	(void) const
{
	String	msg	= this->_set_reply_base (ERR_BADCHANMASK)
				+ _cmd[1]
				+ " :Invalid channel name\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
