/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_usersdontmatch.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:21:35 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/29 19:56:40 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_usersdontmatch	(void) const
{
	String	msg	= this->_set_reply_base (ERR_USERSDONTMATCH)
				+ ":Can't change mode for other users\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
