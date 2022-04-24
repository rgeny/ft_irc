/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/24 12:49:14 by rgeny            ###   ########.fr       */
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
	std::vector<User *>::iterator	it	= this->_data._users.begin(),
									ite	= this->_data._users.end();
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
}

void	Command::_check_cmd	(std::vector<std::string> & cmd)
{
	CmdsFct::iterator	it = this->_cmds_fct.find(case_proof(cmd[0]));
	if (it != this->_cmds_fct.end())
		(this->*(it->second))(cmd);
}

bool	Command::_nick_already_used	(std::string & nickname) const
{
	USERS_LIST	users = this->_data._users;

	for (USERS_IT it = users.begin(), ite = users.end(); it != ite; it++)
	{
		if ((*it)->get_nickname() == nickname)
			return (true);
	}
	return (false);
}
