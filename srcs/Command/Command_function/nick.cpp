/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 16:17:09 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

int		Command::_nick	(std::vector<std::string> & cmd)
{
	std::string	oldest_nickname = this->_client->get_nickname();

	if (cmd.size() <= 1)
	{
		this->_reply.add_arg(cmd[0]);
		std::string final_msg = this->_reply.forge(ERR_NONICKNAMEGIVEN);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	else if (this->_nick_already_used(cmd[1]))
	{
		this->_reply.add_arg(cmd[1]);
		std::string	final_msg = this->_reply.forge(ERR_NICKNAMEINUSE);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	else if (this->_data._historical.nick_is_lock(cmd[1]))
	{
		this->_reply.add_arg(cmd[1]);
		std::string	final_msg = this->_reply.forge(ERR_UNAVAILRESOURCE);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	else if (static_cast<User *>(this->_client)->get_specific_mode(USERMODE_r))
	{
		std::string	final_msg = this->_reply.forge(ERR_RESTRICTED);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	else if (this->_client->set_nickname(cmd[1]) == false)
	{
		this->_reply.add_arg(cmd[1]);
		std::string final_msg = this->_reply.forge(ERR_ERRONEUSNICKNAME);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	this->_data._historical.new_node(oldest_nickname, cmd[1]);
	return (0);













//	if (cmd.size() <= 1)
//	{
//		this->_reply.add_arg(cmd[0]);
//		std::string final_msg = this->_reply.forge(ERR_NONICKNAMEGIVEN);
//		this->_client->add_to_queue(final_msg);
//		return (-1);
//	}
//	else
//	{
//		this->_reply.add_arg(cmd[1]);
//		std::cout << "nickname: " << cmd[1] << std::endl;
//		if (cmd.size() > 1)
//		{
//			if (this->_client->set_nickname(cmd[1]) == false)
//			{
//				std::string final_msg = this->_reply.forge(ERR_ERRONEUSNICKNAME);
//				std::cout	<< "msg forge : " 
//							<< final_msg << "\n";
//				this->_client->add_to_queue(final_msg);
//				return (-1);
//			}
//			std::cout << "NICKNAME SET: " << this->_client->get_nickname() << std::endl;
//		}
//		return (0);
//	}
//	return (-1);
}
