/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 19:31:27 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::main	(void)
{
	(*this->_users_it) = (*this->_users_it);
	this->_is_user = this->_get_user_type();
	this->_parse();
	this->_check_cmd();
//	MSGS_LIST &	msgs	= this->_msgs;
//	MSGS_IT &	it		= this->_msgs_it;
//	MSGS_IT &	ite 	= this->_msgs_ite;
//
//	it = msgs.begin();
//	ite = msgs.end();
//
//	while (it != ite)
//	{
//		this->_check_cmd();
//		it++;
//	}
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
	this->_cmd = split(this->_msg, " ");

//	std::vector<String>	tmp = split(this->_msg, "\r\n");
//
//	this->_msgs.clear();
//	std::vector<String>::iterator	it = tmp.begin(),
//									ite = tmp.end();
//	while (it != ite)
//	{
//		this->_msgs.push_back(split(*it, " "));
//		it++;
//	}
}

void	Command::_check_cmd	(void)
{
//	CmdsFct::iterator	it = this->_cmds_fct.find((*this->_msgs_it)[0]);
	CmdsFct::iterator	it = this->_cmds_fct.find(this->_cmd[0]);

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

bool 	Command::chan_exist(String chan_name) const
{
    if (_chans.find(chan_name) == _chans.end())
        return (false);
    return (true);
}
