/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_userhost.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:58:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/02 16:53:27 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_userhost	(String userhost_list) const
{
    User *cur_user = (*this->_users_it);
    String nickname = cur_user->get_nickname();
    String msg	= this->_set_msg_base(this->_hostname
                                    , "302 "
                                    + nickname
                                    , ":" 
                                    + userhost_list
                                    , "")
                                    + "\r\n";
    cur_user->add_to_queue(msg);
	return (SUCCESS);
}
