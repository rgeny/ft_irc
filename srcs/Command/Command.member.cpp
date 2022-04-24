/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 12:26:54 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::main	(void)
{
	(*this->_users_it) = (*this->_users_it);
	this->_is_user = this->_get_user_type();
	this->_parse();

	MSGS_LIST &	msgs	= this->_msgs;
	MSGS_IT &	it		= this->_msgs_it;
	MSGS_IT &	ite 	= this->_msgs_ite;

	it = msgs.begin();
	ite = msgs.end();

	while (it != ite)
	{
		this->_check_cmd(*it);
		it++;
	}
}

bool	Command::_get_user_type	(void)
{
	USERS_IT	it	= this->_users.begin(),
				ite	= this->_users.end();
	while (it != ite)
	{
		if (*it == (*this->_users_it))
			return (true);
		it++;
	}
	return (false);
}

void	Command::_parse	(void)
{
	std::vector<std::string>	tmp = split(this->_msg, "\r\n");

	this->_msgs.clear();
	std::vector<std::string>::iterator	it = tmp.begin(),
										ite = tmp.end();
	while (it != ite)
	{
		this->_msgs.push_back(split(*it, " "));
		it++;
	}
}

void	Command::_check_cmd	(std::vector<std::string> & cmd)
{
	CmdsFct::iterator	it = this->_cmds_fct.find(case_proof(cmd[0]));
	if (it != this->_cmds_fct.end())
	{
		e_error	error = (this->*(it->second))(cmd);
		this->_cmd_error(error);
	}
}

bool	Command::_nick_already_used	(std::string & nickname) const
{
	USERS_LIST	users = this->_users;

	for (USERS_IT it = users.begin(), ite = users.end(); it != ite; it++)
	{
		if ((*it)->get_nickname() == nickname)
			return (true);
	}
	return (false);
}
