/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 15:51:47 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define HOSTNAME "127.0.0.1"
# define SERVER_NAME "MajinBoo"
# define DFL_TIMEOUT 4

# include <iostream>
# include <string>
# include <vector>
# include "User.hpp"
# include "Command.hpp"
# include "Message.hpp"
# include "ServerData.hpp"
# include "Historical.hpp"

class Server
	:private Socket
	,private ServerData
{
	public:
		typedef std::vector<User *>			USERS_LIST;
		typedef USERS_LIST::iterator		USERS_IT;
		typedef std::map<User *, time_t>	NEW_USERS;
		typedef NEW_USERS::iterator			NEW_USERS_IT;
		typedef int							SOCKET;

		Server	(std::string	password
				,SOCKET			port = PORT);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);

	private:
		std::string				_buf;
		fd_set					_rfds;
		fd_set					_wfds;
		Command					_cmd;

		Server	(Server & src);

		void	_init_fds		(void);
		void	_check_fds		(void);
		void	_new_user		(void);
		void	_del_user		(USERS_IT & it);
		void	_check_tmp_user	(USERS_IT & it);
		void	_read_user_msg	(USERS_IT & it);
};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

