/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_namreply.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:56:22 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/12 23:37:46 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_namreply	(String name_list) const
{
	String msg	= this->_set_msg_base(this->_servername, String(RPL_NAMREPLY) + " " + (*this->_users_it)->get_nickname()
							+ " =", this->_cmd[1] + " :"
							+ name_list)
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}