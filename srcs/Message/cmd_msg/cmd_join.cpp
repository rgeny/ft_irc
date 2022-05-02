/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/02 18:47:16 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_join	(void) const
{
/*
C  ->  JOIN #test
S <-   :dan!~d@0::1 JOIN #test
S <-   :irc.example.com MODE #test +nt
S <-   :irc.example.com 332 alice #test :This is my cool channel! https://irc.com
S <-   :irc.example.com 333 alice #test dan!~d@localhost 1547691506
S <-   :irc.example.com 353 dan = #test :@dan
S <-   :irc.example.com 366 dan #test :End of /NAMES list.
*/
	Channel::CHAN_USER_LIST *tmp = NULL;
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname() 
									+ "!"
									+ (*_users_it)->get_username()
									+ "@"
									+ (*_users_it)->get_host(), JOIN, ":"
									+ this->_cmd[1])
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	for (Channel::CHAN_USER_LIST::iterator it = ((*_chans_it).second)->get_chan_user_list().begin(); it != ((*_chans_it).second)->get_chan_user_list().end(); it++)
	{
		String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
										+ "!" + (*_users_it)->get_username()
										+ "@" + (*_users_it)->get_host(), JOIN, ":"
										+ this->_cmd[1])
										+ "\r\n";
		(*it).second->add_to_queue(msg);
	}
	msg	= this->_set_msg_base(this->_hostname, MODE, this->_cmd[1] + " +nt")
					+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	String name_list;
	tmp = &(*_chans_it).second->get_chan_user_list();
	for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
	{
		std::cout << "Users in this channel: " << (*it).second->get_nickname() << std::endl;
		if (it != tmp->begin())
			name_list += " ";
		if ((*it).second->get_chan_usermode_vec(this->_cmd[1])[1] == true)
			name_list += "@";
		name_list += (*it).second->get_nickname();
	}
	if ((*_chans_it).second->has_topic())
	{
		msg	= this->_set_msg_base(this->_hostname, "332 " + (*this->_users_it)->get_nickname() + " " + this->_cmd[1]
						, 
						(*_chans_it).second->get_topic())
						+ "\r\n";
		(*this->_users_it)->add_to_queue(msg);
	}
	msg	= this->_set_msg_base(this->_hostname, "353 " + (*this->_users_it)->get_nickname()
							+ " =", this->_cmd[1] + " :"
							+ name_list)
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	msg	= this->_set_msg_base(this->_hostname, "366 "
							+ (*this->_users_it)->get_nickname(), this->_cmd[1]
							+ " :End of /NAMES list.")
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}