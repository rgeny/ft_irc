/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 15:33:05 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

Socket::SOCKET		Socket::_srv_socket	= SOCKET_ERROR;
Socket::TIMEVAL		Socket::_timeout	= { 0, 100 };
Socket::SOCKET		Socket::_max		= SOCKET_ERROR;
Socket::SOCKET_LIST	Socket::_socket_list;

Socket:: Socket	(int port)
{
	std::cout	<< "Socket dfl constructor."
			<< std::endl;
	if (Socket::_srv_socket == SOCKET_ERROR)
	{
		Socket::_srv_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (errno != 0)
			throw  error_opening_socket ();
		this->_socket = Socket::_srv_socket;
		this->_socket_list[this->_socket] = 1;

		SOCKADDR_IN		sin;
		sin.sin_addr.s_addr	= htonl(INADDR_ANY);
		sin.sin_port		= htons(port);
		sin.sin_family		= AF_INET;
		if (bind(this->_socket, (SOCKADDR *)&sin, sizeof(sin)) == SOCKET_ERROR)
			return ;
		if (listen(this->_socket, QUEUE) == SOCKET_ERROR)
			return ;
	}
	else
	{
		this->_socket = accept(Socket::_srv_socket, NULL, NULL);
		if (errno != 0)
			throw error_accept_failed ();
		this->_socket_list[this->_socket] = 1;
	}
	//tmp
	SOCKET_LIST_IT	it	= this->_socket_list.begin(),
					ite	= this->_socket_list.end();
	for (; it != ite; it++)
	{
		std::cout	<< "Socket(number) : "
					<< (*it).first
					<< "("
					<< (*it).second
					<< ")\n";
	}
	//fin tmp
}

Socket:: Socket	(const Socket & src)
	:_socket(src._socket)
{
	std::cout	<< "Socket cpy constructor."
				<< std::endl;
	this->_socket_list[this->_socket]++;
	//tmp
	SOCKET_LIST_IT	it	= this->_socket_list.begin(),
					ite	= this->_socket_list.end();
	for (; it != ite; it++)
	{
		std::cout	<< "Socket(number) : "
					<< (*it).first
					<< "("
					<< (*it).second
					<< ")\n";
	}
	//fin tmp

	(void)src;
}

Socket::~Socket	(void)
{
	std::cout	<< "Socket destructor."
				<< std::endl;
	if (this->_socket >= 0)
	{
		if (this->_socket == Socket::_srv_socket)
			Socket::_srv_socket = SOCKET_ERROR;
		if (this->_socket_list[this->_socket] == 1)
		{
			close(this->_socket);
			this->_socket_list.erase(this->_socket);
		}
		else
			this->_socket_list[this->_socket]--;
		this->_socket = SOCKET_ERROR;
	}
	//tmp
	SOCKET_LIST_IT	it	= this->_socket_list.begin(),
					ite	= this->_socket_list.end();
	if (it == ite)
		std::cout	<< "Socket not found\n";
	else
	{
		for (; it != ite; it++)
		{
			std::cout	<< "Socket(number) : "
						<< (*it).first
						<< "("
						<< (*it).second
						<< ")\n";
		}
	}
	//fin tmp
}
