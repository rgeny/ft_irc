/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_privmsg.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:52:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
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
        String current_target = *it;
        String	msg	= this->_set_msg_base((*_users_it)->get_nickname() 
                                        + "!"
                                        + (*_users_it)->get_username()
                                        + "@"
                                        + (*_users_it)->get_host(), PRIVMSG, current_target + " "
                                        + chat_msg)
                                        + "\r\n";
        if (current_target[0] != '#' && this->_user_exist(current_target))
            this->_get_user(current_target)->add_to_queue(msg);
        else if (current_target[0] == '#')
        {
            Channel *current_chan = NULL;
            if (this->_chan_exist(current_target) == true)
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

	return (SUCCESS);
}
