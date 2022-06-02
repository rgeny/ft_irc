/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_creationtime.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:40:15 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/01 19:53:14 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <sstream>
#include "Message.hpp"



e_error	Message::_rpl_creationtime	(void) const
{
	Channel *cur_chan = (*this->_chans_it).second;
	User &	cur_user	= *(*this->_users_it);
    time_t creation_time = cur_chan->get_creation();
    std::stringstream    tmp;
    tmp << creation_time;
    String    s(tmp.str());

	String	msg	= this->_set_reply_base(RPL_CREATIONTIME)
				+ cur_chan->get_chan_name()
				+ " "
				+ s
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
