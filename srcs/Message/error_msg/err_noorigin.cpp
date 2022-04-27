/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_noorigin.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:44:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:34:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_noorigin	(void) const
{
	String	msg	= this->_set_reply_base (ERR_NOORIGIN)
				+ ":No origin specified\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
