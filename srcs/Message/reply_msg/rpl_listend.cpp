/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_listend.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:00:08 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 20:01:08 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Message.hpp"

e_error	Message::_rpl_listend	(void) const
{
	String	msg	= this->_set_reply_base(RPL_ENDOFBANLIST)
                + (*_users_it)->get_nickname()
				+ " :End of channel list."
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}