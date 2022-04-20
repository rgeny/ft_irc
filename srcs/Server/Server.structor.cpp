/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:06:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/20 06:06:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server:: Server	(std::string	password
				,SOCKET			port)
	:Socket(port)
	,_password(password)
	,_hostname(HOSTNAME)
{
	std::cout	<< "Server dfl constructor."
				<< std::endl;
	if (errno != 0)
		throw error_opening_socket ();
	FD_ZERO(&this->_wfds);
	FD_ZERO(&this->_rfds);
}

Server:: Server	(Server & src)
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
	for (USERS_IT it = users.begin(), ite = users.end(); it != ite; it++)
		delete (*it);
}
