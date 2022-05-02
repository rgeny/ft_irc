/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_topic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:23:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/02 16:01:12 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_topic	(int choice) const
{
	if (choice == 1)
	{
		String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
										+ "!" + (*_users_it)->get_username()
										+ "@"
										+ this->_hostname, std::string(TOPIC) + " " + this->_cmd[1] , (*this->_chans_it).second->get_topic())
										+ "\r\n";
		(*this->_users_it)->add_to_queue(msg);
		for (Channel::CHAN_USER_LIST::iterator it = ((*_chans_it).second)->get_chan_user_list().begin(); it != ((*_chans_it).second)->get_chan_user_list().end(); it++)
		{
			if ((*it).second != *_users_it)
			{
				String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
											+ "!" + (*_users_it)->get_username()
											+ "@"
											+ this->_hostname, std::string(TOPIC) + " " + this->_cmd[1] , (*this->_chans_it).second->get_topic())
											+ "\r\n";
				(*it).second->add_to_queue(msg);
			}
		}
	}
	else if (choice == 2)
	{
		String	msg;
		if ((*_chans_it).second->get_topic().empty())
		{
			msg	= this->_set_msg_base(this->_hostname, "331 " + (*this->_users_it)->get_nickname() + " " + this->_cmd[1]
						, 
						":No topic is set.")
						+ "\r\n";
		}
		else
		{
			msg	= this->_set_msg_base(this->_hostname, "332 " + (*this->_users_it)->get_nickname() + " " + this->_cmd[1]
								,
								(*_chans_it).second->get_topic())
								+ "\r\n";
		}
		(*this->_users_it)->add_to_queue(msg);
		return (SUCCESS);
	}
	return (SUCCESS);
}