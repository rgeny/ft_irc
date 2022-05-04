/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 21:35:09 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::main			(void)
{
	while (!FD_ISSET(STDIN_FILENO, &this->_rfds))
	{
		this->_init_fds();
		this->select(&this->_rfds, &this->_wfds);

		if (this->is_set(&this->_rfds))
			this->_new_user();
		else
			this->_check_fds();
		this->_ping_user();
	}
}

void	Server::_init_fds		(void)
{
	USERS_LIST &	users = this->_users;
	USERS_IT &		it = this->_users_it;
	USERS_IT &		ite = this->_users_ite;

	FD_ZERO	(&this->_wfds);
	FD_ZERO	(&this->_rfds);
	FD_SET	(STDIN_FILENO
			,&this->_rfds);
	this->add_in_fds(&this->_rfds);

	for (it = users.begin(), ite = users.end(); it != ite; it++)
	{
		(*it)->add_in_fds(&this->_rfds);
		if (!(*it)->is_empty_send_queue())
			(*it)->add_in_fds(&this->_wfds);
	}
}

void	Server::_check_fds		(void)
{
	USERS_LIST &	users = this->_users;
	USERS_IT &		it = this->_users_it;
	USERS_IT &		ite = this->_users_ite;

	for (it = users.begin(), ite = users.end(); it != ite; it++)
	{
		if ((*it)->is_set(&this->_wfds))
			(*it)->send();
		else if (this->_check_tmp_user())
			this->_del_user();
		else if ((*it)->is_set(&this->_rfds)
				|| !(*it)->is_empty_recv_queue())
		{
			this->_read_user_msg();
		}
		this->_msg.clear();
	}
}

void	Server::_new_user	(void)
{
	User *	new_user = new User;
	this->_tmp_users[new_user] = time(NULL) + TIME_TO_CONNECT;
	this->_users.push_back(new_user);
}

void	Server::_del_user		(void)
{
	delete (*this->_users_it);
	this->_tmp_users.erase(*this->_users_it);
	this->_users.erase(this->_users_it);
}

bool	Server::_check_tmp_user	(void)
{
	TMP_USERS &	tmp_users	= this->_tmp_users;
	time_t		cur_time	= time(NULL);

	if (tmp_users.find(*this->_users_it) != tmp_users.end())
	{
		if (this->_tmp_users[*this->_users_it] < cur_time)
			return (true);
		else if ((*this->_users_it)->reason == TIMEOUT_CO
				&& (*this->_users_it)->co_is_complete())
		{
			this->_tmp_users.erase(*this->_users_it);
		}
	}
	return (false);
}

void	Server::_read_user_msg	(void)
{
	int	n = (*this->_users_it)->receive(this->_msg);

	if (n == 0)
		this->_del_user();
	else if (n > 0)
	{
		if (this->_msg.compare(END_OF_MSG) != 0)
			this->Command::main();
	}
}

void	Server::_ping_user	(void)
{
	USERS_LIST &	users = this->_users;
	USERS_IT &		it = this->_users_it;
	USERS_IT &		ite = this->_users_ite;
	time_t			cur_time = time(NULL);

	for (it = users.begin(), ite = users.end(); it != ite; it++)
	{
		if (this->_tmp_users.find(*it) == this->_tmp_users.end()
			&& (*it)->get_t_last_msg() + TIME_FOR_PING < cur_time)
		{
			(*it)->reason = TIMEOUT_PING;
			this->_tmp_users[*it] = cur_time + TIME_TO_PONG;
			String	msg	= "PING "
						+ this->_servername
						+ "\r\n";
			(*it)->add_to_queue(msg);
		}
	}
}
