/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_whoisuser.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:18:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/08 14:58:12 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_whoisuser	(String user_details) const
{
	String msg	= this->_set_msg_base(this->_hostname, String(RPL_WHOISUSER) + " " + (*this->_users_it)->get_nickname()
							, this->_cmd[1]
                            + " "
							+ user_details)
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}