/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_restricted.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:19:13 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 18:00:34 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_restricted		(void) const
{
	std::string	msg	= this->_set_reply_base(ERR_RESTRICTED)
					+ ":Your connection is restricted!\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
