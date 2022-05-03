/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_privmsg.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:52:23 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/03 16:15:32 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_privmsg	(String chat_msg) const
{
/*
    # :amy!amychan@foo.bar.com PRIVMSG rory :hello comment vas-tu?
*/
    std::vector<String> target_list;
    target_list = split(this->_cmd[1], ",");
	// Channel::CHAN_USER_LIST *tmp = NULL;
    for (std::vector<String>::iterator it = target_list.begin(), ite = target_list.end(); it != ite; it++)
    {
        String current_target = *it; //******************* BOUM ****************************//
        String	msg	= this->_set_msg_base((*_users_it)->get_nickname() 
                                        + "!"
                                        + (*_users_it)->get_username()
                                        + "@"
                                        + (*_users_it)->get_host(), PRIVMSG, current_target + " "
                                        + chat_msg)
                                        + "\r\n";
        if (current_target[0] != '#' && user_exist(current_target))
            get_user(current_target)->add_to_queue(msg);
        else if (current_target[0] == '#')
        {
            Channel *current_chan = NULL;
            if (chan_exist(current_target) == true)
                current_chan = _chans.find(current_target)->second;
            if (current_chan != NULL)
            {
                for (Channel::CHAN_USER_LIST::iterator it = current_chan->get_chan_user_list().begin(), ite = current_chan->get_chan_user_list().end(); it != ite; it++)
                {
                    if (it->first != (*_users_it)->get_nickname())
                        it->second->add_to_queue(msg);
                }
            }
        }
    }
	// for (Channel::CHAN_USER_LIST::iterator it = ((*_chans_it).second)->get_chan_user_list().begin(); it != ((*_chans_it).second)->get_chan_user_list().end(); it++)
	// {
	// 	String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
	// 									+ "!" + (*_users_it)->get_username()
	// 									+ "@" + (*_users_it)->get_host(), JOIN, ":"
	// 									+ this->_cmd[1])
	// 									+ "\r\n";
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
	// 	if ((*it).second->get_chan_usermode_vec(this->_cmd[1])[1] == true)
	// 		name_list += "@";
	// 	name_list += (*it).second->get_nickname();
	// }
	// if ((*_chans_it).second->has_topic())
	// {
	// 	msg	= this->_set_msg_base(this->_hostname, "332 " + (*this->_users_it)->get_nickname() + " " + this->_cmd[1]
	// 					, 
	// 					(*_chans_it).second->get_topic())
	// 					+ "\r\n";
	// 	(*this->_users_it)->add_to_queue(msg);
	// }
	// msg	= this->_set_msg_base(this->_hostname, "353 " + (*this->_users_it)->get_nickname()
	// 						+ " =", this->_cmd[1] + " :"
	// 						+ name_list)
	// 						+ "\r\n";
	// (*this->_users_it)->add_to_queue(msg);
	// msg	= this->_set_msg_base(this->_hostname, "366 "
	// 						+ (*this->_users_it)->get_nickname(), this->_cmd[1]
	// 						+ " :End of /NAMES list.")
	// 						+ "\r\n";
	// (*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
