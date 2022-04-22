/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 12:20:41 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define DFL_TIMEOUT 15

# include <iostream>
# include <string>
# include <vector>
# include "Command.hpp"

class Server
	:virtual private Socket
	,virtual private Command
{
	public:
		typedef int							SOCKET;

		Server	(std::string	password
				,SOCKET			port = PORT);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);

	private:
		fd_set					_rfds;
		fd_set					_wfds;

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

