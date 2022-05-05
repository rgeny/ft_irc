/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 16:35:28 by rgeny            ###   ########.fr       */
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
	this->_cmd = split(this->_msg, " ");
	
	for (size_t i = 0; i < this->_cmd.size(); i++)
	{
		std::vector<String>	expand = this->_expand_mask(this->_cmd[i]);
		if (expand.size() > 0)
			std::cout	<< this->_cmd[i]
						<< " become :"
						<< std::endl;
		for (size_t j = 0; j < expand.size(); j++)
			std::cout	<< expand[j]
						<< std::endl;
		if (expand.size() > 0)
			std::cout	<< std::endl;
	}
}

void	Command::_check_cmd	(void)
{
	if (!this->_check_prefix())
		return ;

	CmdsFct::iterator	it = this->_cmds_fct.find(this->_cmd[0]);

	if (it != this->_cmds_fct.end())
	{
		e_error	error = (this->*(it->second))();
		this->_cmd_error(error);
	}
}

bool	Command::_check_prefix	(void)
{
	if (this->_cmd[0][0] == ':')
	{
		String &	first_word = this->_cmd[0];
		String		sub = first_word.substr(1, first_word.size());

		if((*this->_users_it)->get_nickname() != sub)
		{
			this->_cmd_error(ERROR_BAD_PREFIX);
			return (false);
		}
		this->_cmd.erase(this->_cmd.begin());
	}
	return (true);
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

bool 	Command::user_exist_in_chan(Channel &chan, String nickname) const
{
    if ((chan.get_chan_user_list()).find(nickname) == (chan.get_chan_user_list()).end())
        return (false);
    return (true);
}

bool 	Command::is_operator(String nickname, Channel &chan)
{
	if (user_exist_in_chan(chan, nickname) == true)
	{
		if (((*_users_it)->get_chan_usermode_vec(chan.get_chan_name()))[USERMODE_o] == true)
			return (true);
		return (false);
	}
	else
		return (false);
}

String	Command::concat_last_args(size_t start_index)
{
	String c_str;
	
	if (start_index < _cmd.size())
	{
		for (CMD::iterator it = _cmd.begin() + start_index; it != _cmd.end(); it++)
		{
			if (it != _cmd.begin() + start_index)
				c_str += " ";
			c_str += *it;
		}
	}
	return (c_str);
}

void Command::leave_all (void)
{
	std::cout << "Current user: " << (*_users_it)->get_nickname() << std::endl;
	User::CHAN_USERMODE & chan_usermode = (*_users_it)->get_chan_usermode();
	if (chan_usermode.size() == 0)
		_err_badchanmask();
	else if (chan_usermode.size() > 0)
	{
		User::CHAN_USERMODE::iterator it = chan_usermode.begin();
		User::CHAN_USERMODE::iterator ite = chan_usermode.end();
		while (it != ite)
		{
			_cmd.clear();
			_cmd.push_back("part");
			_cmd.push_back((*it).first);
			_cmd.push_back(":Left");
			_cmd.push_back("all");
			_cmd.push_back("channels");
			_part();
			it = chan_usermode.begin();
			ite = chan_usermode.end();
		}
		_err_badchanmask();
	}
}

