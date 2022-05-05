/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_myinfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:21:45 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 14:24:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_myinfo	(void) const
{
	String	msg	= this->_set_reply_base(RPL_MYINFO)
				+ this->_servername
				+ " "
				+ SERVER_VER
				+ " "
				+ USER_MODE
				+ " "
				+ CHANNEL_MODE
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
