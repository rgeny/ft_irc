/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/08 16:52:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

SOCKET	Socket::_srv_socket = SOCKET_ERROR;

Socket:: Socket	(void)
{
	
	(void)socket;
	if (Socket::_srv_socket == SOCKET_ERROR)
	{
		Socket::_srv_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (errno != 0)
			throw  error_opening_socket ();
		this->_socket = Socket::_srv_socket;
	}
	else
		this->_socket = accept(Socket::_srv_socket, NULL, NULL);
	std::cout	<< "Socket dfl constructor."
				<< std::endl;
}

Socket:: Socket	(Socket & src)
{
	(void)src;
	std::cout	<< "Socket cpy constructor."
				<< std::endl;
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
