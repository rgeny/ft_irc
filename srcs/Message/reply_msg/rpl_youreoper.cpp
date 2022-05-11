/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_youreoper.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:49:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 14:51:29 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_youreoper	(void) const
{
	String	msg	= this->_set_reply_base(RPL_YOUREOPER)
				+ ":You are now an IRC operator.\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
