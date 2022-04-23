/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 16:45:41 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

int		Command::_nick	(std::vector<std::string> & cmd)
{
	std::string	oldest_nickname = this->_client->get_nickname();
	std::string final_msg;

	if (!this->_client->get_passwd_is_sent())
	{
		return (-1);
	}
	else if (cmd.size() <= 1)
	{
		this->_reply.add_arg(cmd[0]);
		final_msg = this->_reply.forge(ERR_NONICKNAMEGIVEN);
		return (-1);
	}
	else if (this->_nick_already_used(cmd[1]))
	{
		this->_reply.add_arg(cmd[1]);
		final_msg = this->_reply.forge(ERR_NICKNAMEINUSE);
		return (-1);
	}
	else if (this->_data._historical.nick_is_lock(cmd[1]))
	{
		this->_reply.add_arg(cmd[1]);
		final_msg = this->_reply.forge(ERR_UNAVAILRESOURCE);
		return (-1);
	}
	else if (static_cast<User *>(this->_client)->get_specific_mode(USERMODE_r))
	{
		final_msg = this->_reply.forge(ERR_RESTRICTED);
		return (-1);
	}
	else if (this->_client->set_nickname(cmd[1]) == false)
	{
		this->_reply.add_arg(cmd[1]);
		final_msg = this->_reply.forge(ERR_ERRONEUSNICKNAME);
		return (-1);
	}
	if (!final_msg.empty())
		this->_client->add_to_queue(final_msg);
	this->_data._historical.new_node(oldest_nickname, cmd[1]);
	return (0);
}
