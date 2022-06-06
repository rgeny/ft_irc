/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_part.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:21:05 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/02 17:09:22 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_part (String reason) const
{
	User *cur_user = (*this->_users_it);
	String nickname = cur_user->get_nickname();
	String username = cur_user->get_username();
	Channel *cur_chan = (*this->_chans_it).second;
	Channel::CHAN_USER_LIST &chan_ulist = cur_chan->get_chan_user_list();
	String host = cur_user->get_host();
	String	msg	= this->_set_msg_base(nickname
									+ "!" 
									+ username
									+ "@"
									+ this->_hostname
									, this->_cmd[0]
									, this->_cmd[1] 
									+ (!reason.empty()? " " + reason: ""))
									+ "\r\n";
	cur_user->add_to_queue(msg);
	for (Channel::CHAN_USER_LIST::iterator it = chan_ulist.begin(), ite = chan_ulist.end(); it != ite; it++)
	{
		if ((*it).second != cur_user)
		{
	        String	msg	= this->_set_msg_base(nickname
									+ "!" 
									+ username
									+ "@"
									+ this->_hostname
									, this->_cmd[0] 
									, this->_cmd[1] 
									+ (!reason.empty()? " " + reason: ""))
									+ "\r\n";
			(*it).second->add_to_queue(msg);
		}
	}
	return (SUCCESS);
}
