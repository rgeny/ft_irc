/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:57:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 22:21:53 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

Socket &	Socket::operator=	(Socket & src)
{
	if (this->_socket_list[this->_socket] == 1)
	{
		close(this->_socket);
		this->_socket_list.erase(this->_socket);
	}
	this->_socket = src._socket;
	this->_socket_list[this->_socket]++;
	return (*this);
}

