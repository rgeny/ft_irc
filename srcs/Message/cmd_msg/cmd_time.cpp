/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_time.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:03:00 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_time	(void) const
{
	String  msg	= this->_set_msg_base(this->_servername, "391 "
                                    + (*this->_users_it)->get_nickname()
                                    + ""
                                    , this->_servername
                                    , time(0))
						            + "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
