/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:59:23 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/10 18:05:26 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

void	Socket::add_in_fds	(fd_set * fds)
{
	if (!FD_ISSET(this->_socket, fds))
	{
		FD_SET(this->_socket, fds);
		if (this->_socket > Socket::_max)
			Socket::_max = this->_socket;
	}
}

int		Socket::select		(fd_set * rfds
							,fd_set * wfds)
{
	if (this->_socket == Socket::_srv_socket)
	{
		SOCKET	max = Socket::_max + 1;
		Socket::_max = SOCKET_ERROR;
		return (::select(max, rfds, wfds, NULL, &Socket::_timeout));
	}
	return (-1);
}

int	Socket::receive	(std::string & str)
{
	char	s[BUF_SIZE] = "";
	int		n			= ::recv(this->_socket, s, BUF_SIZE - 1, 0);
	str = s;
	return (n);
}

int			Socket::send	(std::string & msg)
{
	return (::send(this->_socket, msg.c_str(), msg.length(), 0));
}

bool		Socket::is_set	(fd_set * fds) const
{
	return (FD_ISSET(this->_socket, fds));
}
