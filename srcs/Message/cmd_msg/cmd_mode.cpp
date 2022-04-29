/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:56:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/29 18:58:07 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_mode	(void) const
{

	// Channel::CHAN_USER_LIST *tmp = NULL;
	// String	msg	= this->_set_msg_base((*_users_it)->get_nickname() + "!" + (*_users_it)->get_username() + "@" + this->_hostname, JOIN, ":" + this->_cmd[1])
	// 				+ "\r\n";
	// (*this->_users_it)->add_to_queue(msg);
	// for (Channel::CHAN_USER_LIST::iterator it = ((*_chans_it).second)->get_chan_user_list().begin(); it != ((*_chans_it).second)->get_chan_user_list().end(); it++)
	// {
	// 	String	msg	= this->_set_msg_base((*_users_it)->get_nickname() + "!" + (*_users_it)->get_username() + "@" + this->_hostname, JOIN, ":" + this->_cmd[1])
	// 				+ "\r\n";
	// 	(*it).second->add_to_queue(msg);
	// }
	// msg	= this->_set_msg_base(this->_hostname, MODE, this->_cmd[1] + " +nt")
	// 				+ "\r\n";
	// (*this->_users_it)->add_to_queue(msg);
	// String name_list;
	// tmp = &(*_chans_it).second->get_chan_user_list();
	// for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
	// {
	// 	std::cout << "Users in this channel: " << (*it).second->get_nickname() << std::endl;
	// 	if (it != tmp->begin())
	// 		name_list += " ";
	// 	if ((*it).second->get_chan_usermode(this->_cmd[1])[1] == true)
	// 		name_list += "@";
	// 	name_list += (*it).second->get_nickname();
	// }
	// msg	= this->_set_msg_base(this->_hostname, "353 " + (*this->_users_it)->get_nickname() + " =", this->_cmd[1] + " :" + name_list)
	// 				+ "\r\n";
	// (*this->_users_it)->add_to_queue(msg);
	// msg	= this->_set_msg_base(this->_hostname, "366 " + (*this->_users_it)->get_nickname(), this->_cmd[1] + " :End of /NAMES list.")
	// 				+ "\r\n";
	// (*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}