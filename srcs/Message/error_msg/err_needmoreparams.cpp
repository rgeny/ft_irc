/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_needmoreparams.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:35:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 18:23:56 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_needmoreparams	(String reason) const
{
	String	msg	= this->_set_reply_base(ERR_NONICKNAMEGIVEN)
				+ this->_cmd[0]
				+ " :" 
				+ reason
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
