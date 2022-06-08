/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/08 16:44:07 by abesombes        ###   ########.fr       */
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
	static std::string const	delimiter(" ");
	String &			str = this->_msg;

	this->_cmd.clear();
	for (size_t pos = str.find(delimiter);
		 	pos != String::npos
			&& str[0] != ':';
		 pos = str.find(delimiter))
	{
		if (pos > 0)
			this->_cmd.push_back(str.substr(0, pos));
		this->_msg.erase(0, pos + delimiter.size());
	}
	if (!str.empty())
	{
		if (str[0] == ':')
			this->_cmd.push_back(str.substr(1, str.size()));
		else
			this->_cmd.push_back(str);
	}
	str.clear();
}

void	Command::_check_cmd	(void)
{
	if (!this->_check_prefix())
		return ;

	CmdsFct::iterator	it = this->_cmds_fct.find(this->_cmd[0]);

	for (size_t i = 0; i < this->_cmd.size(); i++)
	{
		std::cout	<< this->_cmd[i]
					<< std::endl;
	}

	if (it != this->_cmds_fct.end())
	{
		e_error	error = (this->*(it->second))();
		this->_cmd_error(error);
	}
	else
		this->_err_unknowncommand();
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
	Channel::CHAN_USER_LIST *chan_ulist = NULL;
	chan_ulist = &(chan.get_chan_user_list());
	
    if (chan_ulist && chan_ulist->find(nickname) == chan_ulist->end())
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
	std::cout << "Chan_usermode.size(): " << chan_usermode.size() << std::endl;
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
			std::cout << "chan_name: " << (*it).first << std::endl;
			_part();
			it = chan_usermode.begin();
			ite = chan_usermode.end();
		}
	}
}

