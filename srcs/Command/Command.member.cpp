/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/03 11:01:05 by ayzapata         ###   ########.fr       */
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


bool 	Command::user_exist_in_chan(Channel &chan, String nickname) const
{
    if (chan.get_chan_user_list().find(nickname) == chan.get_chan_user_list().end())
        return (false);
    return (true);
}

bool 	Command::is_operator(String nickname, Channel &chan)
{
	if (user_exist_in_chan(chan, nickname) == true)
	{
		if (((*_users_it)->get_chan_usermode_vec(chan.get_chan_name()))[1] == true)
			return (true);
		return (false);
	}
	else
		return (false);
}

bool 	Command::user_exist(String nickname) const
{
	// for (Data::USERS_IT it = this->_users.begin(), ite = _users.end(); it!= ite; it++)
	for (size_t i = 0; i < _users.size(); i++)
	{
		if (_users[i]->get_nickname() == nickname)
			return (true);
	}
    return (false);
}

User *Command::get_user(String nickname)
{
	for (size_t i = 0; i < _users.size(); i++)
	{
		if (_users[i]->get_nickname() == nickname)
			return (_users[i]);
	}
    return (NULL);
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
		// for (User::CHAN_USERMODE::iterator it = chan_usermode.begin(), ite = chan_usermode.end(); it != ite; it++)
		// {
		// 	std::cout << "Chan listed in Chan_usermode: " << it->first << std::endl;
		// }
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


		
		// for (User::CHAN_USERMODE::iterator it = chan_usermode.begin(); it != ite; it++)
		// {
		// 	std::cout << "Is active in this channel: " << it->first << std::endl;
		// 	_cmd.clear();
		// 	_cmd.push_back("part");
		// 	_cmd.push_back((*it).first);
		// 	_cmd.push_back(":Left");
		// 	_cmd.push_back("all");
		// 	_cmd.push_back("channels");
		// 	_part();
		// }
		// User::CHAN_USERMODE::iterator it = chan_usermode.begin();
		// std::cout << "Is active in this channel: " << it->first << std::endl;
		// _cmd.clear();
		// _cmd.push_back("part");
		// _cmd.push_back((*it).first);
		// _cmd.push_back(":Left");
		// _cmd.push_back("all");
		// _cmd.push_back("channels");
		// _part();
		_err_badchanmask();
	}
}