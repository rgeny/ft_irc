/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:52:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/12 17:37:46 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP
# define SOCKET_ERROR -1
# define PORT 6697
# define BUF_SIZE 513
# define QUEUE 42

# include <iostream>
# include <unistd.h>
# include "Exceptions.hpp"
# include <sys/types.h>
# include <sys/socket.h>
# include <errno.h>
# include <sstream>
# include <vector>


class Socket
{
	public:
		typedef int					SOCKET;
		typedef struct sockaddr_in	SOCKADDR_IN;
		typedef struct sockaddr		SOCKADDR;
		typedef struct timeval		TIMEVAL;

		Socket	(int port = PORT);
		~Socket	(void);

		void	add_in_fds	(fd_set * fds) const;
		int		select		(fd_set * rfds
							,fd_set * wfds);
		int		receive		(std::vector<std::string> & str) const;
		int		send		(std::string & msg) const ;
		bool	is_set		(fd_set * fds) const;

	private:
		SOCKET			_socket;
		static SOCKET	_srv_socket;
		static TIMEVAL	_timeout;
		static SOCKET	_max;
		

		Socket	(const Socket & src);

		Socket &	operator=	(Socket & src);
};

std::ostream &	operator<<	(std::ostream & os
							,Socket & src);
#endif

