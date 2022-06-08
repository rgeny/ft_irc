/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_whoreply.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:46:37 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/08 14:56:57 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_whoreply	(String who_list) const
{
	String msg	= this->_set_msg_base(this->_hostname, String(RPL_WHOREPLY) + " " + (*this->_users_it)->get_nickname()
							, this->_cmd[1]
							+ " "
							+ who_list)
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}