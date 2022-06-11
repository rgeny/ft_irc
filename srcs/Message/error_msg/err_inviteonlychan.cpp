/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_inviteonlychan.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:22:17 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/10 16:34:27 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_inviteonlychan	(void) const
{
	String	msg	= this->_set_reply_base (ERR_INVITEONLYCHAN)
				+ this->_cmd[1]
				+ " :Cannot join channel (invite only)\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
