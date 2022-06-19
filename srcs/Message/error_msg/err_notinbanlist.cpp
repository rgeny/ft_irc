/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_notinbanlist.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:17:22 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/19 15:25:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_notinbanlist	(String chan_name, String target) const
{
	String	msg	= this->_set_reply_base(ERR_NOTINBANLIST)
                + chan_name
                + " "
                + target
                + " b "
				+ ":Channel ban list does not contain "
                + target
                + "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
