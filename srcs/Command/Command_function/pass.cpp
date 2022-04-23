/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:13:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 15:35:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

int		Command::_pass	(std::vector<std::string> & msg)
{
	if (msg.size() < 2)
	{
		this->_reply.add_arg(msg[0]);
		std::string	final_msg = this->_reply.forge(ERR_NEEDMOREPARAMS);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	else if (static_cast<User *>(this->_client)->co_is_complete())
	{
		std::string	final_msg = this->_reply.forge(ERR_ALREADYREGISTRED);
		this->_client->add_to_queue(final_msg);
		return (0);
	}
	else
	{
		this->_client->set_passwd_is_sent(this->_data._password == msg[1]);
		return (this->_client->get_passwd_is_sent());
	}
	return (-1);
}
