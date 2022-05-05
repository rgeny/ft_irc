/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:56:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/05 16:09:04 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"


e_error	Message::_cmd_mode	(int broadcast) const
{
	String	msg;
	// if (user_chan == 1) // Complex USER in CHANNEL
	// {
		// :dan!d@127.0.0.1 MODE #aa Krilin :+mv
		
		msg	= this->_set_msg_base((*_users_it)->get_nickname()
										+ "!" + (*_users_it)->get_username()
										+ "@"
										+ this->_hostname, 
										this->_cmd[0] 
										+ " " 
										+ this->_cmd[1]
										, ":" + _cmd[2] + (!_cmd[3].empty()? " " + _cmd[3] : ""))
										+ "\r\n";

	// }
	// else if (user_chan == 2) // Single USER ou CHANNEL
	// {
	// 	// :dan!d@127.0.0.1 MODE #aa :+t

	// 	msg	= this->_set_msg_base((*_users_it)->get_nickname()
	// 									+ "!" + (*_users_it)->get_username()
	// 									+ "@"
	// 									+ this->_hostname, 
	// 									this->_cmd[0] 
	// 									+ " " 
	// 									+ this->_cmd[1], ":" + _cmd[2])
	// 									+ "\r\n";
	// }
	(*this->_users_it)->add_to_queue(msg);
	if (broadcast == 1)
	{
		Channel::CHAN_USER_LIST chan_ulist = ((*_chans_it).second)->get_chan_user_list();
		for (Channel::CHAN_USER_LIST::iterator it = chan_ulist.begin(), ite = chan_ulist.end(); it != ite; it++)
		{
			if ((*_users_it) != it->second)
				(*it).second->add_to_queue(msg);
		}
	}
	return (SUCCESS);
}