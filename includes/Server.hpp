/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/22 19:14:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define HOSTNAME "127.0.0.1"

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include "User.hpp"
# include "Command.hpp"
# include "Message.hpp"
# include "Channel.hpp"

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
		std::vector<User *>								_users;
		std::map<std::string, Channel *>				_chans;
		std::string										_hostname;
		std::string										_password;
		std::string										_buf;
		fd_set											_rfds;
		fd_set											_wfds;
		Command											_cmd;

		Server	(Server & src);

		void	init_fds		(void);
		void	check_fds		(void);
		void	del_client		(USERS_IT & it);
};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

