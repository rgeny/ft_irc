/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_umodeunknownflag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:11:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/04 14:43:52 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_umodeunknownflag	(String failed, String reason) const
{
	String	msg	= this->_set_reply_base(ERR_UMODEUNKNOWNFLAG)
                + (!failed.empty() ? failed + " ": "")
                + reason 
                + "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
