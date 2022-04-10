/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:06:01 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/10 18:01:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server:: Server	(std::string	password
				,int			port)
	:_password(password)
	,_hostname(HOSTNAME)
{
	std::cout	<< "Server dfl constructor."
				<< std::endl;
	if (errno != 0)
		throw error_opening_socket ();
}

Server:: Server	(Server & src)
{
	(void)src;
	std::cout	<< "Server cpy constructor."
				<< std::endl;
}

Server::~Server	(void)
{
	for (int i = 0; i < this->_clients.size(); i++)
		delete this->_clients[i];
	std::cout	<< "Server destructor."
				<< std::endl;
}
