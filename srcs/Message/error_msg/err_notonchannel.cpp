/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_notonchannel.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:15:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/11 19:01:14 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_notonchannel	(void) const
{
	String	msg	= this->_set_reply_base (ERR_NOTONCHANNEL)
				+ this->_cmd[1]
				+ " :You're not on that channel\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
