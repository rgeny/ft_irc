/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/09 20:22:50 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

SOCKET	Socket::_srv_socket = SOCKET_ERROR;

Socket:: Socket	(void)
{
	std::cout	<< "Socket dfl constructor."
			<< std::endl;
	// (void)socket;
	if (Socket::_srv_socket == SOCKET_ERROR)
	{
		Socket::_srv_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (errno != 0)
			throw  error_opening_socket ();
		this->_socket = Socket::_srv_socket;
	}
	else
	{
		std::cout	<< Socket::_srv_socket
					<< "\n";
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
