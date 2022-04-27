/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 16:38:33 by abesombe         ###   ########.fr       */
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
S <-   :irc.example.com 353 dan = #test :@dan
S <-   :irc.example.com 366 dan #test :End of /NAMES list.
*/
	std::string	msg	= this->_set_msg_base((*_users_it)->get_nickname() + "!" + (*_users_it)->get_username() + "@" + this->_hostname, JOIN, ":" + (*this->_msgs_it)[1])
					+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	msg	= this->_set_msg_base(this->_hostname, MODE, (*this->_msgs_it)[1] + " +nt")
					+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	std::string name_list;
	Channel::CHAN_USER_LIST *tmp = NULL;
	tmp = &(*_chans_it).second->get_chan_user_list();
	for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
		std::cout << (*it).second->get_nickname() << std::endl;
	msg	= this->_set_msg_base(this->_hostname, "353", (*this->_msgs_it)[1] + " +nt")
					+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
