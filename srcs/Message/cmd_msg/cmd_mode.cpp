/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:56:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/05 10:35:40 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_mode	(int broadcast) const
{
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
									+ "!" + (*_users_it)->get_username()
									+ "@"
									+ this->_hostname, 
									this->_cmd[0] 
									+ " " 
									+ this->_cmd[1], _cmd[2])
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	if (broadcast == 1)
	{
		Channel::CHAN_USER_LIST chan_ulist = ((*_chans_it).second)->get_chan_user_list();
		for (Channel::CHAN_USER_LIST::iterator it = chan_ulist.begin(), ite = chan_ulist.end(); it != ite; it++)
		{
			String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
										+ "!" + (*_users_it)->get_username()
										+ "@"
										+ this->_hostname, 
										this->_cmd[0] 
										+ " " 
										+ this->_cmd[1], _cmd[2])
										+ "\r\n";
			(*this->_users_it)->add_to_queue(msg);
		}
	}
	return (SUCCESS);
}