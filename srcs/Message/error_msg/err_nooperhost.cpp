/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nooperhost.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:53:23 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 14:57:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_nooperhost	(void) const
{
	String	msg	= this->_set_reply_base(ERR_NOOPERHOST)
				+ ":No O-lines for your host.\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
