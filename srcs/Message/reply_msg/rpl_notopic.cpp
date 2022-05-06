/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_notopic.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:04:57 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 11:23:37 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_notopic	(void) const
{
    String msg	= this->_set_msg_base(this->_hostname, "331 " + (*this->_users_it)->get_nickname() + " " + this->_cmd[1]
						, 
						":No topic is set.")
						+ "\r\n";
    (*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}	