/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/18 22:34:31 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <cstring>
std::string Server::_hello = "Welcome to the Server\n";
char		Server::_buffer[1024] = "";

void	Server::main			(void)
{
	while (true)
	{
		this->init_rfds();
		this->select(&this->_rfds, &this->_wfds);
		if (FD_ISSET(STDIN_FILENO, &this->_rfds))
			return ;
		else if (this->is_set(&this->_rfds))
		{
			std::cout	<< "1\n";
			this->_clients.push_back(new Client);
		}
		else
		{
			for (int i = 0; i < this->_clients.size(); i++)
			{
				if (this->_clients[i]->is_set(&this->_wfds))
					this->_clients[i]->send();
				if (this->_clients[i]->is_set(&this->_rfds))
				{
					std::string buf;
					int			n = this->_clients[i]->receive(buf);
					if (n == 0)
						this->del_client(i);
					else
					{
						std::cout	<< "buf : "
									<< buf
									<< std::endl;
						this->_clients[i]->add_to_queue(buf);
					}
				}
			}
		}
	}
}

void	Server::init_rfds		(void)
{
	FD_ZERO	(&this->_wfds);
	FD_ZERO	(&this->_rfds);
	FD_SET	(STDIN_FILENO
			,&this->_rfds);
	this->add_in_fds(&this->_rfds);
	for (int i = 0; i < this->_clients.size(); i++)
	{
		this->_clients[i]->add_in_fds(&this->_rfds);
		if (!this->_clients[i]->is_empty_msg_queue())
			this->_clients[i]->add_in_fds(&this->_wfds);
	}
}


void	Server::del_client		(int i)
{
	delete this->_clients[i];
	this->_clients.erase(this->_clients.begin() + i);
}
