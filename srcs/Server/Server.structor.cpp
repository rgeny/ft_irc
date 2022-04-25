/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:06:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 12:27:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server:: Server	(std::string	password
				,SOCKET			port)
	:Socket(port)
	,Data(password)
//	,ServerData()
{
	this->_password = password;
	this->_servername = SERVER_NAME;
	this->_hostname = HOSTNAME;
	std::cout	<< "Server dfl constructor."
				<< std::endl;
	if (errno != 0)
		throw (error_opening_socket ());
	FD_ZERO(&this->_wfds);
	FD_ZERO(&this->_rfds);
}

Server:: Server	(Server & src)
//	:ServerData()
	:Data(src)
{
	std::cout	<< "Server cpy constructor."
				<< std::endl;
	(void)src;
}

Server::~Server	(void)
{
	std::cout	<< "Server destructor."
				<< std::endl;
	std::vector<User *> &	users = this->_users;
//	for (USERS_IT it = users.begin(), ite = users.end(); it != ite; it++)
//		delete (*it);
}
