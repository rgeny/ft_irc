/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/08 18:11:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define PORT 6697
# define HOSTNAME 127.0.0.1
# define QUEUE 42

# include <iostream>
# include "Socket.hpp"

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

		void	main	(void);


	private:
		Socket		_socket;
		std::string	_hostname;
		std::string	_password;

		//
		Socket	_client_tmp;
		//



};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

