/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_luserclient.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:49:16 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 19:33:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_luserclient	(void) const
{
	std::stringstream	n_users,
						n_services;
	n_users	<< this->_count_users();
	n_services	<< this->_count_services();
	String	msg	= this->_set_reply_base(RPL_LUSERCLIENT)
			 	+ ":There is "
				+ n_users.str()
				+ " users and "
				+ n_services.str()
				+ " services on 1 server."
				+ END_OF_MSG;
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
