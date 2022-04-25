/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 17:18:10 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::main	(void)
{
	this->_client = (*this->_users_it);
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
		if (*it == this->_client)
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
		this->_check_error(error);
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
void	Command::_check_error	(e_error code)
{
	if (code == ERROR_PASSWDMISMATCH)
	{
		this->add_arg(CLOSE);
		this->add_arg(this->_client->get_nickname());
		this->add_arg(this->_servername);
		this->add_arg(BADPASSWD);
		std::string	final_msg = this->forge(ERROR);
		this->_client->add_to_queue(final_msg);
		this->_client->be_disconnected = true;
	}
}
