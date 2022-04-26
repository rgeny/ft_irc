/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_passwdmismatch.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:41:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 15:55:24 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_passwdmismatch	(void) const
{
	std::string	msg	= this->_set_reply_base(ERR_PASSWDMISMATCH)
					+ ":incorrect password\r\n";
	(*this->_users_it).add_to_queue(msg);
	return (ERROR_BAD_PASSWD);
}
