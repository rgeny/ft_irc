/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/22 12:27:28 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::main	(Client * client
						,std::string & cmd)
{
	this->_client = client;
	this->_is_user = this->_get_user_type();
	this->_parse(cmd);

	ClientCmds::iterator	it	= this->_client_cmds.begin(),
							ite = this->_client_cmds.end();
	while (it != ite)
	{
		this->_check_cmd(*it);
		it++;
	}
}

bool	Command::_get_user_type	(void)
{
	std::vector<User *>::iterator	it	= this->_users.begin(),
									ite	= this->_users.end();
	while (it != ite)
	{
		if (*it == this->_client)
			return (true);
		it++;
	}
	return (false);
}

void	Command::_parse	(std::string & cmd)
{
	std::vector<std::string>	tmp = split(cmd, "\r\n");

	this->_client_cmds.clear();
	std::vector<std::string>::iterator	it = tmp.begin(),
										ite = tmp.end();
	while (it != ite)
	{
		this->_client_cmds.push_back(split(*it, " "));
		it++;
	}
//	std::string	tmp;
//	this->tokens = split (cmd_str, " ");
//	this->_user = user;
}

void	Command::_check_cmd	(std::vector<std::string> & cmd)
{
	CmdsFct::iterator	it = this->_cmds_fct.find(case_proof(cmd[0]));
	if (it != this->_cmds_fct.end())
		(this->*(it->second))(cmd);
}

int		Command::_nick	(std::vector<std::string> & cmd)
{
	Message reply;

	if (cmd.size() <= 1)
	{
		reply.add_arg(cmd[0]);
		std::string final_msg = reply.forge("127.0.0.1", ERR_NONICKNAMEGIVEN);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	else
	{
		reply.add_arg(cmd[1]);
		std::cout << "nickname: " << cmd[1] << std::endl;
		if (cmd.size() > 1)
		{
			if (this->_client->set_nickname(cmd[1]) == false)
			{
				std::string final_msg = reply.forge("127.0.0.1", ERR_ERRONEUSNICKNAME);
				this->_client->add_to_queue(final_msg);
				return (-1);
			}
//		if (this->_client->get_user().is_nick_valid(cmd[1]) == false)
//		{
//			std::string final_msg = reply.forge("127.0.0.1", ERR_ERRONEUSNICKNAME, _msg_list);
//			this->_client->add_to_queue(final_msg);
//			return (-1);
//		}
//		if (this->_client->get_nickname() != "anonymous")
//		{
//			std::cout << "CHANGE OF NICK!!" << std::endl;
//		}
//		else if (cmd.size() > 1)
//		{
//			if (_user_list.find(cmd[1]) == _user_list.end())
//			{
//				std::cout << "I am in\n";
//				this->_client->get_user().nickname.set(cmd[1]);
//				_user_list[cmd[1]] = &this->_client->get_user(); // we update the user_list with the new nickname / user
//			}

			std::cout << "NICKNAME SET: " << this->_client->get_nickname() << std::endl;

		}
		return (0);
	}
	return (-1);
}

int		Command::_user	(std::vector<std::string> & cmd)
{
	Message reply;

	if (this->_client->get_nickname() != "anonymous")
	{
		if (cmd.size() > 4)
		{
			std::string u(cmd[1]);
			std::string tmp = "";
			User & cur_user = static_cast<User &>(*this->_client);
			cur_user.set_username(u);
			for (size_t i = 5; i < cmd.size(); i++)
				tmp += cmd[i];
			cur_user.set_realname(tmp);
//			if (_user_list.find(cmd[1]) == _user_list.end())
//				_user_list[cmd[1]] = &this->_client->get_user();
//			reply.add_arg(this->_client->get_user().fci());
			reply.add_arg(cur_user.get_nickname() + "!" + cur_user.get_username() + "@127.0.0.1");

//			std::string	final_msg = this->_msg.main(this->_client, RPL_WELCOME);

			std::string final_msg = cur_user.get_nickname() + "!" + cur_user.get_username() + "@127.0.0.1" + reply.forge("127.0.0.1", RPL_WELCOME);
			this->_client->add_to_queue(final_msg);
		}
		return 0;
	}
	return (-1);
}
