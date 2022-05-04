/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_creationtime.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:40:15 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/04 19:32:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <sstream>
#include "Message.hpp"



e_error	Message::_rpl_creationtime	(void) const
{
	User &	cur_user	= *(*this->_users_it);
    time_t creation_time = (*_chans_it).second->get_creation();
    std::stringstream    tmp;
    tmp << creation_time;
    String    s(tmp.str());

	String	msg	= this->_set_reply_base(RPL_CREATIONTIME)
				+ (*_chans_it).second->get_chan_name()
				+ " "
				+ s
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
