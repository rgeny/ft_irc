/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_part.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:21:05 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/02 18:22:39 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_part (String reason) const
{
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
									+ "!" + (*_users_it)->get_username()
									+ "@"
									+ this->_hostname, this->_cmd[0] , this->_cmd[1] + (!reason.empty()? " " + reason: ""))
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	// std::cout << "Current User: " << ((*_chans_it).second)->get_chan_user_list().begin()->first << std::endl;
	for (Channel::CHAN_USER_LIST::iterator it = ((*_chans_it).second)->get_chan_user_list().begin(), ite = ((*_chans_it).second)->get_chan_user_list().end(); it != ite; it++)
	{
		// std::cout << "Current User: " << it->first << std::endl;
		if ((*it).second != *_users_it)
		{
	        String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
									+ "!" + (*_users_it)->get_username()
									+ "@"
									+ this->_hostname, this->_cmd[0] , this->_cmd[1] + (!reason.empty()? " " + reason: ""))
									+ "\r\n";
			(*it).second->add_to_queue(msg);
		}
	}
	return (SUCCESS);
}
