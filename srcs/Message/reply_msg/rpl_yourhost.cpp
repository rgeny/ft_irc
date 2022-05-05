/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_yourhost.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:23:36 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 11:28:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_yourhost	(void) const
{
	User &	cur_user	= *(*this->_users_it);
	String	msg	= this->_set_reply_base(RPL_YOURHOST)
				+ "Your host is "
				+ this->_servername
				+ ", running version "
				+ SERVER_VER
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
