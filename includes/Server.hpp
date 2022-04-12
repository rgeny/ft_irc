/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/12 17:40:13 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define HOSTNAME "127.0.0.1"

# include <iostream>
# include <string>
# include <vector>
# include "Socket.hpp"
# include "Client.hpp"

typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;

//tmp
#define MAX_CLIENTS 10
//fin tmp

class Server
{
	public:
		Server	(std::string	password
				,int			port = PORT);
		Server	(Server & src);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);
		void	init_rfds		(void);
		void	del_client		(int	i);

	private:
		Socket					_socket;
		std::vector<Client *>	_clients;
		std::string				_hostname;
		std::string				_password;
		fd_set					_rfds;
		fd_set					_wfds;
		static char				_buffer[1024];
		static std::string 		_hello;

};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

