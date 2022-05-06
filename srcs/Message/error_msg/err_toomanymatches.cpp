/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_toomanymatches.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:20:48 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 15:28:35 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_toomanymatches	(void) const
{
	String	msg	= this->_set_reply_base(ERR_TOOMANYMATCHES)
				+ this->_cmd[1]
				+ ":Result too long\r\n";
	
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
