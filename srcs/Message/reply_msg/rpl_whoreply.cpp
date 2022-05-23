/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_whoreply.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:46:37 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/23 11:51:08 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_whoreply	(String who_list) const
{
	String msg	= this->_set_msg_base(this->_servername, String(RPL_WHOREPLY) + " " + (*this->_users_it)->get_nickname()
							+ " =", this->_cmd[1] + " :"
							+ who_list)
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}