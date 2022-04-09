/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/09 20:27:05 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define PORT 6697
# define HOSTNAME "127.0.0.1"
# define QUEUE 42

# include <iostream>
# include <string>
# include <vector>
# include "Socket.hpp"
# include "Client.hpp"

typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;

//tmp
#define MAX_CLIENTS 10
#define BUF_SIZE    512
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
		void	new_client		(void);
		void	del_client		(Client &	client
								,char *		buffer
								,int		i);
		int		read_client		(int i);
		void	write_client	(int i);
		void	send_msg			(char *	buffer);
		void	send_message_to_all_clients	(Client			client
											,const char *	buffer
											,char			from_server);

	private:
		Socket				_socket;
		std::vector<Socket *>	_clients;
		// Socket				_t;
		std::string			_hostname;
		std::string			_password;
		fd_set				_rfds;
		fd_set				_wfds;
		static char			_buffer[1024];
		static std::string 	_hello;
		//tmp
		// Socket	_client_tmp;
		//fin tmp

};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

