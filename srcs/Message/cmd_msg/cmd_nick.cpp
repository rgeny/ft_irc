/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:02:32 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 22:18:22 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_nick	(String & oldest) const
{
	if (oldest == DFL_NICKNAME)
		return (ERROR_CONTINUE);
	String	msg	= this->_set_sender(oldest)
				+ " "
				+ NICK
				+ " "
				+ (*this->_users_it)->get_nickname()
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
