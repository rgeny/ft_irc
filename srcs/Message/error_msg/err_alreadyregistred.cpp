/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_alreadyregistred.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:40:29 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 15:54:05 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_alreadyregistred	(void) const
{
	std::string	msg	= this->_set_reply_base(ERR_ALREADYREGISTRED)
					+ ":Unauthorized command (already registred)\r\n";
	(*this->_users_it).add_to_queue(msg);
	return (ERROR_CONTINUE);
}
