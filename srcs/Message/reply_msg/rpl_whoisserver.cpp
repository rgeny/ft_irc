/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_whoisserver.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:18:07 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/08 14:58:33 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_whoisserver(void) const
{
	String msg	= this->_set_msg_base(this->_servername, String(RPL_WHOISSERVER) + " " + (*this->_users_it)->get_nickname()
							, this->_cmd[1] + " " + _hostname + " :"
							+ _hostname)
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}