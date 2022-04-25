/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_needmoreparams.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:35:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 18:00:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_needmoreparams	(void) const
{
	std::string	msg	= this->_set_reply_base(ERR_NONICKNAMEGIVEN)
					+ (*this->_msgs_it)[0]
					+ " :Not enough parameters\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
