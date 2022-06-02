/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_endofwho.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:05 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/01 19:53:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_endofwho	(void) const
{
	Channel *cur_chan = (*this->_chans_it).second;
	String	msg	= this->_set_reply_base(RPL_ENDOFWHO)
                + cur_chan->get_chan_name()
				+ " :End of /WHO list."
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}