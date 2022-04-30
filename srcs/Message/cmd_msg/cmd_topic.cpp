/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_topic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:23:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/30 21:30:07 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_topic	(void) const
{
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
									+ "!" + (*_users_it)->get_username()
									+ "@"
									+ this->_hostname, std::string(TOPIC) + " " + this->_cmd[1] , (*this->_chans_it).second->get_topic())
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	for (Channel::CHAN_USER_LIST::iterator it = ((*_chans_it).second)->get_chan_user_list().begin(); it != ((*_chans_it).second)->get_chan_user_list().end(); it++)
	{
		String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
									+ "!" + (*_users_it)->get_username()
									+ "@"
									+ this->_hostname, std::string(TOPIC) + " " + this->_cmd[1] , (*this->_chans_it).second->get_topic())
									+ "\r\n";
		(*it).second->add_to_queue(msg);
	}
	return (SUCCESS);
}
