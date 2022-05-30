/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_userhost.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:58:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_userhost	(String userhost_list) const
{
    String  msg	= this->_set_msg_base(this->_hostname, "302 "
                                    + (*this->_users_it)->get_nickname()
                                    , ":" + userhost_list
                                    , "")
                                    + "\r\n";
    (*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
