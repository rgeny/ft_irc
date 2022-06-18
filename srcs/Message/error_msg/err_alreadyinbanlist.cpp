/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_alreadyinbanlist.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:59:17 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/18 22:09:19 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

// :*.freenode.net 697 abesombes #tt abesombes1!*@* b :Channel ban list already contains abesombes1!*@*

e_error	Message::_err_alreadyinbanlist	(String chan_name, String target) const
{
	String	msg	= this->_set_reply_base(ERR_ALREADYINBANLIST)
                + chan_name
                + " "
                + target
                + " b "
				+ ":Channel ban list already contains "
                + target
                + "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
