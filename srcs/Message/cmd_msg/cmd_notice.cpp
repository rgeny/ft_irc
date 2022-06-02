/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_notice.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:47:10 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/02 16:03:14 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_notice	(String chat_msg) const
{
    Channel::CHAN_USER_LIST chan_user_list;
    std::vector<String> target_list;
    target_list = split(this->_cmd[1], ",");
    for (std::vector<String>::iterator it = target_list.begin(), ite = target_list.end(); it != ite; it++)
    {
        String current_target = *it;
        String nickname = (*this->_users_it)->get_nickname();
	    String username = (*this->_users_it)->get_username();
        String host = (*this->_users_it)->get_host();
        String	msg	= this->_set_msg_base(nickname
                                        + "!"
                                        + username
                                        + "@"
                                        + host, NOTICE, current_target + " "
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
                chan_user_list = current_chan->get_chan_user_list();
                for (Channel::CHAN_USER_LIST::iterator it = chan_user_list.begin(), ite = chan_user_list.end(); it != ite; it++)
                {
                    if (it->first != nickname)
                        it->second->add_to_queue(msg);
                }
            }
        }
    }

	return (SUCCESS);
}
