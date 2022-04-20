/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/20 05:55:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <cstring>

void	Server::main			(void)
{
	while (!FD_ISSET(STDIN_FILENO, &this->_rfds))
	{
		this->init_fds();
		this->select(&this->_rfds, &this->_wfds);

		if (this->is_set(&this->_rfds))
			this->_clients.push_back(new Client);
		else
			this->check_fds();
	}
}

void	Server::init_fds		(void)
{
	std::vector<Client *> &	clients = this->_clients;

	FD_ZERO	(&this->_wfds);
	FD_ZERO	(&this->_rfds);
	FD_SET	(STDIN_FILENO
			,&this->_rfds);
	this->add_in_fds(&this->_rfds);

	for (CLIENTS_IT	it = clients.begin(), ite = clients.end(); it != ite; it++)
	{
		(*it)->add_in_fds(&this->_rfds);
		if (!(*it)->is_empty_msg_queue())
			(*it)->add_in_fds(&this->_wfds);
	}
}

void	Server::check_fds		(void)
{
	std::vector<Client *> &	clients = this->_clients;

	for (CLIENTS_IT	it = clients.begin(), ite = clients.end(); it != ite; it++)
	{
		if ((*it)->is_set(&this->_wfds))
			(*it)->send();
		else if ((*it)->is_set(&this->_rfds))
		{
			if ((*it)->receive(this->_buf) == 0)
				this->del_client(it);
			else
			{
				std::cout	<< "buf : "
							<< this->_buf
							<< std::endl;
				(*it)->add_to_queue(this->_buf);
			}
		}
	}
}

void	Server::del_client		(CLIENTS_IT & it)
{
	delete (*it);
	this->_clients.erase(it);
}
