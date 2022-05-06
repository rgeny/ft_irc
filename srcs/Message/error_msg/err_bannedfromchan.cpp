/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bannedfromchan.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:13:54 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 17:14:27 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_bannedfromchan	(void) const
{
	String	msg	= this->_set_reply_base (ERR_BANNEDFROMCHAN)
				+ _cmd[1] + " :Cannot join channel (you're banned)\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}

