/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nosuchchannel.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:15:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/29 18:20:52 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_nosuchchannel	(void) const
{
	String	msg	= this->_set_reply_base (ERR_NOSUCHCHANNEL)
				+ this->_cmd[1]
				+ " :No such channel\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
