/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:59:23 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/15 20:14:43 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ircserv.hpp"
#include "Socket.hpp"


void	Socket::add_in_fds	(fd_set * fds) const
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

int	Socket::receive	(std::vector<std::string> & str) const
{
	char	s[BUF_SIZE] = "";
	int		n			= 	recv(this->_socket, s, BUF_SIZE - 1, 0);
	str = split(std::string(s), '\n');
	std::string last_line = str[str.size() - 1];
	if (last_line[last_line.length() - 1] == '\r')
		str[str.size() - 1] = last_line.substr(0, last_line.length() - 1);
	return (n);
}

int			Socket::send	(std::string & msg) const
{
	return (::send(this->_socket, msg.c_str(), msg.length(), 0));
}

bool		Socket::is_set	(fd_set * fds) const
{
	return (FD_ISSET(this->_socket, fds));
}

