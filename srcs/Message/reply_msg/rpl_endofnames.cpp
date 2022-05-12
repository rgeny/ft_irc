/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_endofnames.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:05 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/12 23:30:00 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_endofnames	(void) const
{
	// User *cur_user = (*this->_users_it);
	String	msg	= this->_set_reply_base(RPL_ENDOFNAMES)
                + (*_chans_it).second->get_chan_name()
				+ " :End of /NAMES list."
				+ "\r\n";
	// String msg	= this->_set_msg_base("", "366 "
	// 						+ cur_user->get_nickname(), this->_cmd[1]
	// 						+ " :End of /NAMES list.")
	// 						+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}