/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nonicknamegiven.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:02:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 06:00:53 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_nonicknamegiven	(void) const
{
	String	msg	= this->_set_reply_base(ERR_NONICKNAMEGIVEN)
				+ this->_cmd[0]
				+ " :no nickname given\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
