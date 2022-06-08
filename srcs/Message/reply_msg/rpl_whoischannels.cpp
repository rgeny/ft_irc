/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_whoischannels.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:18:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/08 14:58:41 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_whoischannels	(String user_chan_list) const
{
	String msg	= this->_set_msg_base(this->_hostname, String(RPL_WHOISCHANNELS) + " " + (*this->_users_it)->get_nickname()
							, this->_cmd[1]
							+ " "
							+ user_chan_list)
							+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
    return (SUCCESS);
}