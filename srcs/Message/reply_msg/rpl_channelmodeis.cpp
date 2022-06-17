/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_channelmodeis.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:37:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/17 19:49:35 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_channelmodeis	(void) const
{
	Channel *cur_chan = (*this->_chans_it).second;
	User &	cur_user	= *(*this->_users_it);
	String	msg	= this->_set_reply_base(RPL_CHANNELMODEIS)
				+ cur_chan->get_chan_name()
				+ " "
				+ cur_chan->get_mode_string()
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
