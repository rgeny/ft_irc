/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/09 20:47:36 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <cstring>
std::string Server::_hello = "Welcome to the Server\n";
char		Server::_buffer[1024] = "";

int	max = STDIN_FILENO;

void	Server::main			(void)
{
	
	// std::cout	<< "abc";
	// this->init_rfds();
	// select(this->_socket.get_socket(), &this->_rfds, NULL, NULL, NULL);
	// std::cout	<< "abc";
	// this->new_client();

	while (true)
	{
		this->init_rfds();
		select(max + 1, &this->_rfds, NULL, NULL, NULL);
		if (FD_ISSET(STDIN_FILENO, &this->_rfds))
			return ;
		else if (FD_ISSET(this->_socket.get_socket(), &this->_rfds))
		{
			std::cout	<< "new_client\n";
			this->new_client();
		}
		else
		{
			for (int i = 0; i < this->_clients.size(); i++)
			{
				if (FD_ISSET(this->_clients[i]->get_socket(), &this->_rfds))
				{
					this->read_client(i);
					this->write_client(i);
				}
			}
		}
	}
}
	// int	n	= recv	(this->_clients[0].get_socket(), Server::_buffer, BUF_SIZE -1, 0);
void	Server::init_rfds		(void)
{
	FD_ZERO	(&this->_rfds);
	FD_SET	(STDIN_FILENO
			,&this->_rfds);
	FD_SET	(this->_socket.get_socket()
			,&this->_rfds);
	max = this->_socket.get_socket();
	for (int i = 0; i < this->_clients.size(); i++)
	{
		if (this->_clients[i]->get_socket() > max)
			max = this->_clients[i]->get_socket();
		FD_SET (this->_clients[i]->get_socket(), &this->_rfds);
	}
	// if (!this->_clients.empty())
	// 	FD_SET	(this->_clients[0].get_socket(), &this->_rfds);

	// for (int i = 0; i < this->_clients.size(); i++)
	// {
	// 	std::cout	<< this->_clients[i]->get_socket()
	// 				<< this->_clients[i]->get_nickname()
	// 				<< std::endl;
	// 	FD_SET	(this->_clients[i]->get_socket()
	// 			,&this->_rfds);

	// 	// if (!this->_client[i].queue.empty())
	// 	// 	FD_SET ( this->_clients[i]->socket.get()
	// 	// 			, &this->_wdfs);
	// }
}

void	Server::new_client		(void)
{
	Socket *	tmp	= new Socket;
	// Socket();
	// std::cout	<< "c";
	this->_clients.push_back(tmp);

	// if (read_client() < 0)
	// 	throw error_recv_failed();
	// if (csock > *max)
	// 	*max = csock;
	// FD_SET (csock, &this->_rfds);
	// Client	c = { csock };
	// strncpy	(c.name, buffer, BUF_SIZE - 1);
	// this->_clients.push_back(c);
	// this->_n_client++;
}

void	Server::del_client		(Client &	client
								,char *		buffer
								,int		i)
{
	(void)client;
	(void)buffer;
	(void)i;
}

int		Server::read_client		(int i)
{
	int	n	= recv	(this->_clients[i]->get_socket(), Server::_buffer, BUF_SIZE -1, 0);

	if (n < 0)
	{
		perror("recv()");
		n = 0;
	}
	Server::_buffer[n] = '\0';


	for (int j = 0; j < this->_clients.size(); j++)
	{
		send(this->_clients[j]->get_socket(), Server::_buffer, strlen(Server::_buffer), 0);
	}

	// if (strncmp("NICK", buffer, 4) == 0)
	// {
	// 	int	i = 0;
	// 	while (this->_clients[i]->sock != sock)
	// 		i++;
	// 	this->_clients[i]->name[0] = '\0';
	// 	strncpy	(this->_clients[i]->name, buffer + 5, BUF_SIZE - 1);
	// }
	return n;
}

void	Server::write_client	(int i)
{
//	if (send(this->_clients[i]->get_socket(), this->_hello.c_str(), this->_hello.length(), 0) < 0)
//		throw error_send_failed();
}

void	Server::send_msg			(char *	buffer)
{
	(void)buffer;
}

void	Server::send_message_to_all_clients	(Client			client
											,const char *	buffer
											,char			from_server)
{
	(void)client;
	(void)buffer;
	(void)from_server;
}
