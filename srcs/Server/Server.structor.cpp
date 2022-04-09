/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:06:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/08 19:22:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server:: Server	(std::string	password
				,int			port)
	:_password(password)
	,_hostname(HOSTNAME)
{
	// std::cout	<< "abc";
	if (this->_socket.get_socket() == SOCKET_ERROR)
		throw error_opening_socket ();

	// std::cout	<< "abc";

	SOCKADDR_IN		sin;
	sin.sin_addr.s_addr	= htonl(INADDR_ANY);
	sin.sin_port 		= htons(port);
	sin.sin_family		= AF_INET;	
	if (bind(this->_socket.get_socket(), (SOCKADDR *) &sin, sizeof(sin)) == SOCKET_ERROR)
		throw error_bind_failed (); 
	if (listen(this->_socket.get_socket(), QUEUE) == SOCKET_ERROR)
		throw error_listen_failed ();
	std::cout	<< "Server dfl constructor."
				<< std::endl;
}

Server:: Server	(Server & src)
{
	(void)src;
	std::cout	<< "Server cpy constructor."
				<< std::endl;
}

Server::~Server	(void)
{
	std::cout	<< "Server destructor."
				<< std::endl;
}
