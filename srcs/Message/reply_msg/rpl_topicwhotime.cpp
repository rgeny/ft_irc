/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_topicwhotime.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:04:57 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/03 22:10:52 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_topicwhotime	(void) const
{
    Channel *cur_chan = (*this->_chans_it).second;
    User* cur_user = *this->_users_it;
    String nickname = cur_user->get_nickname();
    String topic = cur_chan->get_topic();
    time_t crea_time = cur_chan->get_topic_creation_time();
    std::stringstream    tmp;
    tmp << crea_time;
    String    creation_time(tmp.str());
    
    User* topic_creator = cur_chan->get_topic_creator();
    String msg	= this->_set_msg_base(this->_hostname
                                    , "333 " 
                                    + nickname
                                    + " " 
                                    + this->_cmd[1]
                                    , topic_creator->get_nickname()
                                    + "!"
                                    + topic_creator->get_username()
                                    + "@"
                                    + topic_creator->get_host() 
                                    + " " 
                                    + creation_time)
                                    + "\r\n";
    cur_user->add_to_queue(msg);
	return (SUCCESS);
}