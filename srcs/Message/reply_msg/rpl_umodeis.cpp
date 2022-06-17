/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_umodeis.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:17:42 by abesombes         #+#    #+#             */
/*   Updated: 2022/06/17 19:51:08 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_umodeis	(String user_mode) const
{
	String msg	= this->_set_msg_base(  this->_hostname, 
                                        String(RPL_UMODEIS) 
                                        + " " 
                                        + this->_cmd[1]
							            , String(":+" + user_mode))
							            + "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}