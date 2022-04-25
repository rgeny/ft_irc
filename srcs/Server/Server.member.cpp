/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 20:18:15 by rgeny            ###   ########.fr       */
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
		if (!(*it)->is_empty_msg_queue())
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
		else if ((*it)->be_disconnected)
			this->_del_user(it);
		else if ((*it)->is_set(&this->_rfds))
			this->_read_user_msg(it);
		else
			this->_check_tmp_user(it);
	}
}

void	Server::_new_user	(void)
{
	User *	new_user = new User;
	this->_tmp_users[new_user] = time(NULL);
	this->_users.push_back(new_user);
	
}

void	Server::_del_user		(USERS_IT & it)
{
	delete (*it);
	this->_tmp_users.erase(*it);
	this->_users.erase(it);
}

void	Server::_check_tmp_user	(USERS_IT & it)
{
	TMP_USERS &	tmp_users	= this->_tmp_users;
	time_t		cur_time	= time(NULL);

	if (tmp_users.find(*it) != tmp_users.end())
	{
		if ((*it)->co_is_complete())
			this->_tmp_users.erase(*it);
		else if (this->_tmp_users[*it] + DFL_TIMEOUT <= cur_time)
			this->_del_user(it);
	}
}

void	Server::_read_user_msg	(USERS_IT & it)
{
	int	n = (*it)->receive(this->_msg);

	if (n == 0)
		this->_del_user(it);
	else if (n > 0)
	{
		if (this->_msg.compare(END_OF_MSG) != 0)
			this->Command::main();
	}
}
