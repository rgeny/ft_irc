/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_topic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:04:57 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/01 19:54:19 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_topic	(void) const
{
    Channel *cur_chan = (*this->_chans_it).second;
    String msg	= this->_set_msg_base(this->_hostname, "332 " + (*this->_users_it)->get_nickname() + " " + this->_cmd[1]
                    , 
                    cur_chan->get_topic())
                    + "\r\n";
    (*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}