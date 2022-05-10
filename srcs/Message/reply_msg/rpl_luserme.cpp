/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_luserme.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:51:04 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 19:55:25 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_luserme	(void) const
{
	std::stringstream	n_users;
	n_users	<< this->_count_users();
	String	msg	= this->_set_reply_base(RPL_LUSERME)
				+ ":I have "
				+ n_users.str()
				+ " clients and 1 server.\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
