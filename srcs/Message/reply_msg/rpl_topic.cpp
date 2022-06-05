/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_topic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:04:57 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/03 19:02:01 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_topic	(void) const
{
    Channel *cur_chan = (*this->_chans_it).second;
    User* cur_user = *this->_users_it;
    String nickname = cur_user->get_nickname();
    String topic = cur_chan->get_topic();
    if (topic.empty())
        topic = ":";
    else
        topic = ":" + topic;
    
    String msg	= this->_set_msg_base(this->_hostname
                                    , "332 "
                                    + nickname
                                    + " " 
                                    + this->_cmd[1]
                                    , topic
                                    )
                                    + "\r\n";
    cur_user->add_to_queue(msg);
    return (SUCCESS);
}