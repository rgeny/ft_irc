/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 15:29:27 by rgeny            ###   ########.fr       */
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
		Server	(std::string	password
				,SOCKET			port = PORT);
		Server	(Server & src);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);


	private:
		fd_set					_rfds;
		fd_set					_wfds;


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

