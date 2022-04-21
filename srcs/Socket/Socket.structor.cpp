/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 17:04:24 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

Socket::SOCKET	Socket::_srv_socket	= SOCKET_ERROR;
Socket::TIMEVAL	Socket::_timeout	= { 0, 100 };
Socket::SOCKET	Socket::_max		= SOCKET_ERROR;

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
	}

}

Socket:: Socket	(const Socket & src)
{
	std::cout	<< "Socket cpy constructor."
				<< std::endl;
	(void)src;
}

Socket::~Socket	(void)
{
	if (this->_socket >= 0)
	{
		close(this->_socket);
		this->_socket = SOCKET_ERROR;
	}
	std::cout	<< "Socket destructor."
				<< std::endl;
}
