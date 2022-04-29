/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_unavailresource.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:06:49 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 06:01:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_unavailresource	(void) const
{
	String	msg	= this->_set_reply_base(ERR_UNAVAILRESOURCE)
				+ this->_cmd[1]
				+ " :Nick/channel is temporarily unavailable\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
