/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_channelmodeis.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:37:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 18:32:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_channelmodeis	(void) const
{
	User &	cur_user	= *(*this->_users_it);
	String	msg	= this->_set_reply_base(RPL_CHANNELMODEIS)
				+ (*_chans_it).second->get_chan_name()
				+ " "
				+ (*_chans_it).second->get_mode_string()
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
