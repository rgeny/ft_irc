/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:06:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 21:34:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server:: Server	(std::string	password
				,SOCKET			port)
	:Socket(port)
	,Data(password)
	,Message()
	,Command()
{
	std::cout	<< "Server dfl constructor."
				<< std::endl;
	if (errno != 0)
		throw (error_opening_socket ());
	FD_ZERO(&this->_wfds);
	FD_ZERO(&this->_rfds);
}

Server:: Server	(Server & src)
	:Socket(PORT)
	,Data(src)
	,Message()
	,Command()
{
	std::cout	<< "Server cpy constructor."
				<< std::endl;
}

Server::~Server	(void)
{
	std::cout	<< "Server destructor."
				<< std::endl;
}
