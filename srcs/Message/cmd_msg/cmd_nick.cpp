/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:02:32 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/02 15:58:49 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_nick	(String & oldest) const
{
	String nickname = (*this->_users_it)->get_nickname();
	if (oldest == DFL_NICKNAME)
		return (ERROR_CONTINUE);
	String	msg	= this->_set_sender(oldest)
				+ " "
				+ NICK
				+ " "
				+ nickname
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
