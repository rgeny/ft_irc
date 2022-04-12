/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/12 18:04:05 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Command.hpp"
#include <cstring>
std::string Server::_hello = "Welcome to the Server\n";
char		Server::_buffer[1024] = "";

void	Server::main			(void)
{
	while (true)
	{
		this->init_rfds();
		this->_socket.select(&this->_rfds, &this->_wfds);
		if (FD_ISSET(STDIN_FILENO, &this->_rfds))
			return ;
		else if (this->_socket.is_set(&this->_rfds))
		{
			std::cout	<< "1\n";
			this->_clients.push_back(new Client("Mr Satan"));
		}
		else
		{
			for (int i = 0; i < this->_clients.size(); i++)
			{
				if (this->_clients[i]->get_socket().is_set(&this->_rfds))
				{
					std::cout	<< "nickname: "
								<< this->_clients[i]->nickname.get()
								<< std::endl;
					std::vector<std::string>	buf;
					int			n = this->_clients[i]->get_socket().receive(buf);
					if (n == 0)
						this->del_client(i);
					else
					{
						std::cout	<< buf.size()
									<< std::endl;
						for (int j = 0; j < buf.size(); j++)
						{
							std::cout	<< "buf[" 
										<< j
										<< "] : "
										<< buf[j]
										<< std::endl;
							Command cmd;
							cmd.parse(buf[j], this->_clients[i]);
							for (int k = 0; k < cmd.cmd.get().size(); k++)
								std::cout	<< cmd.cmd.get()[k] << std::endl;
							this->_clients[i]->get_socket().send(buf[j]);
						}
					}
				}
			}
		}
	}
}

void	Server::init_rfds		(void)
{
	FD_ZERO	(&this->_rfds);
	FD_SET	(STDIN_FILENO
			,&this->_rfds);
	this->_socket.add_in_fds(&this->_rfds);
	for (int i = 0; i < this->_clients.size(); i++)
	{
		this->_clients[i]->get_socket().add_in_fds(&this->_rfds);
	}
}


void	Server::del_client		(int i)
{
	delete this->_clients[i];
	this->_clients.erase(this->_clients.begin() + i);
}
