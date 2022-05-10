/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_unknowncommand.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:42:20 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 21:48:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_unknowncommand	(void) const
{
	if (!((*this->_users_it)->co_is_complete()))
		return (SUCCESS);
	String	msg	= this->_set_reply_base(ERR_UNKNOWNCOMMAND)
				+ this->_cmd[0]
				+ " :Unknown command\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
