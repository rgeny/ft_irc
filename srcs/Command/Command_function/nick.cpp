/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/24 09:13:45 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_nick	(std::vector<std::string> & cmd)
{
	std::string	oldest_nickname = this->_client->get_nickname();
	std::string final_msg;

	if (!this->_client->get_passwd_is_sent())
	{
		this->_reply.set_receiver(this->_client->get_nickname());
		final_msg = this->_reply.forge(ERR_PASSWDMISMATCH);
		this->_client->add_to_queue(final_msg);
		return (ERROR_PASSWDMISMATCH);
	}
	else if (cmd.size() <= 1)
	{
		this->_reply.add_arg(cmd[0]);
		final_msg = this->_reply.forge(ERR_NONICKNAMEGIVEN);
		this->_client->add_to_queue(final_msg);
		return (ERROR_CONTINUE);
	}
	else if (this->_nick_already_used(cmd[1]))
	{
		this->_reply.add_arg(cmd[1]);
		final_msg = this->_reply.forge(ERR_NICKNAMEINUSE);
		this->_client->add_to_queue(final_msg);
		return (ERROR_CONTINUE);
	}
	else if (this->_data._historical.nick_is_lock(cmd[1]))
	{
		this->_reply.add_arg(cmd[1]);
		final_msg = this->_reply.forge(ERR_UNAVAILRESOURCE);
		this->_client->add_to_queue(final_msg);
		return (ERROR_CONTINUE);
	}
	else if (static_cast<User *>(this->_client)->get_specific_mode(USERMODE_r))
	{
		final_msg = this->_reply.forge(ERR_RESTRICTED);
		this->_client->add_to_queue(final_msg);
		return (ERROR_CONTINUE);
	}
	else if (this->_client->set_nickname(cmd[1]) == false)
	{
		this->_reply.add_arg(cmd[1]);
		final_msg = this->_reply.forge(ERR_ERRONEUSNICKNAME);
		this->_client->add_to_queue(final_msg);
		return (ERROR_CONTINUE);
	}
	this->_data._historical.new_node(oldest_nickname, cmd[1]);
	return (SUCCESS);
}
