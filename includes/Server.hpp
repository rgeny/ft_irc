/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/20 05:52:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define HOSTNAME "127.0.0.1"

# include <iostream>
# include <string>
# include <vector>
# include "Client.hpp"

//tmp
#define MAX_CLIENTS 10
//fin tmp

class Server
	:private Socket
{
	public:
		typedef std::vector<Client *>::iterator		CLIENTS_IT;

		Server	(std::string	password
				,int			port = PORT);
		Server	(Server & src);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);
		void	init_fds		(void);
		void	check_fds		(void);
		void	del_client		(CLIENTS_IT & it);

	private:
		std::vector<Client *>	_clients;
		std::string				_hostname;
		std::string				_password;
		std::string				_buf;
		fd_set					_rfds;
		fd_set					_wfds;
};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

