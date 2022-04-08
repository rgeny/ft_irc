/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:52:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/08 16:15:14 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP
# define SOCKET_ERROR -1

# include <iostream>
# include <unistd.h>
# include "Exceptions.hpp"
# include <sys/types.h>
# include <sys/socket.h>
# include <errno.h>

typedef int	SOCKET;
typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;

class Socket
{
	public:
		Socket	(void);
		~Socket	(void);

		const SOCKET &	get_socket	(void)	const;

	private:
		SOCKET			_socket;
		static SOCKET	_srv_socket;

		Socket	(Socket & src);

		Socket &	operator=	(Socket & src);
};

std::ostream &	operator<<	(std::ostream & os
							,Socket & src);
#endif
