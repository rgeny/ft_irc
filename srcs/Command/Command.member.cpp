/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 13:21:19 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::main	(void)
{
	(*this->_users_it) = (*this->_users_it);
	this->_is_user = this->_get_user_type();
	this->_parse();
	this->_check_cmd();
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
	this->_split_msg();
}

void	Command::_check_cmd	(void)
{
	CMD_FCT::iterator	it = this->_cmds_fct.find(this->_cmd[0]);

	if (it != this->_cmds_fct.end())
	{
		e_error	error = (this->*(it->second))();
		this->_cmd_error(error);
	}
}

bool	Command::_nick_already_used	(String & nickname) const
{
	USERS_LIST	users = this->_users;

	for (USERS_IT it = users.begin(), ite = users.end(); it != ite; it++)
	{
		if ((*it)->get_nickname() == nickname)
			return (true);
	}
	return (false);
}

void	Command::_split_msg	(void)
{
	this->_cmd.clear();
	char	delimiter = ' ';

	if (this->_msg[0] == ':')
		this->_msg.erase(0, this->_msg.find(delimiter) + 1);

	size_t	pos	= this->_msg.find(delimiter);
	while (pos != String::npos
			&& this->_msg[0] != ':')
	{
		this->_cmd.push_back(this->_msg.substr(0, pos));
		this->_msg.erase(0, pos + 1);
		pos	= this->_msg.find(delimiter);
	}
	this->_cmd.push_back(this->_msg);
	this->_msg.clear();
}
