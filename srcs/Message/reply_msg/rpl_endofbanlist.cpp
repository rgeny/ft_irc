/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_endofbanlist.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:05 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 15:22:54 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_endofbanlist	(void) const
{
	String	msg	= this->_set_reply_base(RPL_ENDOFBANLIST)
                + (*_chans_it).second->get_chan_name()
				+ " :End of channel ban list"
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}