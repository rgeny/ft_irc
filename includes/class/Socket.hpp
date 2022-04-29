/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:52:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 04:32:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP
# define SOCKET_ERROR -1
# define RECV_ERROR -1
# define SEND_ERROR -1
# define PORT 6697
# define BUF_SIZE 513
# define QUEUE 42

# include <iostream>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <errno.h>
# include <arpa/inet.h>
# include <map>

# include "Exceptions.hpp"
# include "Utils.hpp"
# include "defines.hpp"


class Socket
{
	public:
		typedef int					SOCKET;
		typedef struct sockaddr_in	SOCKADDR_IN;
		typedef struct sockaddr		SOCKADDR;
		typedef struct timeval		TIMEVAL;

				Socket	(int port = PORT);
		virtual	~Socket	(void);

		void	add_in_fds	(fd_set * fds) const;
		int		select		(fd_set * rfds
							,fd_set * wfds);
		int		receive		(String & str) const;
		int		send		(String & msg) const;
		bool	is_set		(fd_set * fds) const;

	private:
		SOCKET							_socket;
		static SOCKET					_srv_socket;
		static TIMEVAL					_timeout;
		static SOCKET					_max;
		static std::map<SOCKET, size_t>	_socket_list;

		Socket	(const Socket & src);

		Socket &	operator=	(Socket & src);
};

#endif

