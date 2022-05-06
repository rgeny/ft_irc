/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:56:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 16:58:13 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"


e_error	Message::_cmd_mode	(int broadcast) const
{
	String	msg;
	String  part1 = (_cmd.size() > 3 ? _cmd[2] + "" : ":" + _cmd[2]);
	String 	part2 = (_cmd.size() > 3 ? " :" + _cmd[3] : "");
	String  final_part = part1 + part2;
		
	msg	= this->_set_msg_base((*_users_it)->get_nickname()
										+ "!" + (*_users_it)->get_username()
										+ "@"
										+ this->_hostname, 
										this->_cmd[0] 
										+ " " 
										+ this->_cmd[1]
										, final_part )
										+ "\r\n";

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