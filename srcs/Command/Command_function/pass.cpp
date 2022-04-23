/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:13:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 17:32:56 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_pass	(std::vector<std::string> & msg)
{
	if (msg.size() < 2)
	{
		this->_reply.add_arg(msg[0]);
		std::string	final_msg = this->_reply.forge(ERR_NEEDMOREPARAMS);
		this->_client->add_to_queue(final_msg);
		return (ERROR_CONTINUE);
	}
	else if (static_cast<User *>(this->_client)->co_is_complete())
	{
		std::string	final_msg = this->_reply.forge(ERR_ALREADYREGISTRED);
		this->_client->add_to_queue(final_msg);
		return (SUCCESS);
	}
	else
	{
		this->_client->set_passwd_is_sent(this->_data._password == msg[1]);
		if (this->_client->get_passwd_is_sent())
			return (SUCCESS);
	}
	return (ERROR_CONTINUE);
}
