/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/20 06:08:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define HOSTNAME "127.0.0.1"

# include <iostream>
# include <string>
# include <vector>
# include "User.hpp"

class Server
	:private Socket
{
	public:
		typedef std::vector<User *>::iterator	USERS_IT;
		typedef int								SOCKET;

		Server	(std::string	password
				,SOCKET			port = PORT);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);

	private:
		std::vector<User *>		_users;
		std::string				_hostname;
		std::string				_password;
		std::string				_buf;
		fd_set					_rfds;
		fd_set					_wfds;

		Server	(Server & src);

		void	init_fds		(void);
		void	check_fds		(void);
		void	del_client		(USERS_IT & it);
};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

