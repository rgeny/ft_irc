/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/18 18:35:01 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define HOSTNAME "127.0.0.1"

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <utility>
# include "Socket.hpp"
# include "Client.hpp"
# include "User.hpp"

typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;

//tmp
#define MAX_CLIENTS 10
//fin tmp

class Server
{
	
	typedef int (Server::*UserCommandPointer)(Client *, std::vector<std::string> const & message);
	typedef std::map<std::string, UserCommandPointer> userCmds;
	// typedef std::map<std::string, UserCommandPointer> serviceCommands;

	
	public:
		Server	(std::string	password
				,int			port = PORT);
		Server	(Server & src);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);
		void	init_rfds		(void);
		void	del_client		(int	i);
		void 	init_cmd_list	(void);
		void	init_msg_list	(void);
		void 	check_cmd(Client *sender, std::vector<std::string> tokens);
		std::string get_msg(std::string msg_code, std::vector<std::string> *args);
		std::string replace_tags(std::string msg_template, std::vector<std::string> *args);
		// void find_replace_tags(std::string & data, std::string toSearch, std::string replaceStr);
		// int		admin(Client *sender, const std::vector<std::string> &msg);
		// int		away(Client *sender, const std::vector<std::string> &msg);
		int		cap(Client *sender, const std::vector<std::string> &msg);
		// int		cnotice(Client *sender, const std::vector<std::string> &msg);
		// int		cprivmsg(Client *sender, const std::vector<std::string> &msg);
		// int		connect(Client *sender, const std::vector<std::string> &msg);
		// int		die(Client *sender, const std::vector<std::string> &msg);
		// int		encap(Client *sender, const std::vector<std::string> &msg);
		// int		error(Client *sender, const std::vector<std::string> &msg);
		// int		help(Client *sender, const std::vector<std::string> &msg);
		// int		info(Client *sender, const std::vector<std::string> &msg);
		// int		invite(Client *sender, const std::vector<std::string> &msg);
		// int		ison(Client *sender, const std::vector<std::string> &msg);
		// int		join(Client *sender, const std::vector<std::string> &msg);
		// int		kick(Client *sender, const std::vector<std::string> &msg);
		// int		kill(Client *sender, const std::vector<std::string> &msg);
		// int		knock(Client *sender, const std::vector<std::string> &msg);
		// int		links(Client *sender, const std::vector<std::string> &msg);
		// int		list(Client *sender, const std::vector<std::string> &msg);
		// int		lusers(Client *sender, const std::vector<std::string> &msg);
		// int		mode(Client *sender, const std::vector<std::string> &msg);
		// int		motd(Client *sender, const std::vector<std::string> &msg);
		// int		names(Client *sender, const std::vector<std::string> &msg);
		// int		namesx(Client *sender, const std::vector<std::string> &msg);
		int			nick(Client *sender, const std::vector<std::string> &msg);
		// int		notice(Client *sender, const std::vector<std::string> &msg);
		// int		oper(Client *sender, const std::vector<std::string> &msg);
		// int		part(Client *sender, const std::vector<std::string> &msg);
		// int		pass(Client *sender, const std::vector<std::string> &msg);
		// int		ping(Client *sender, const std::vector<std::string> &msg);
		// int		pong(Client *sender, const std::vector<std::string> &msg);
		// int		privmsg(Client *sender, const std::vector<std::string> &msg);
		// int		quit(Client *sender, const std::vector<std::string> &msg);
		// int		rehash(Client *sender, const std::vector<std::string> &msg);
		// int		rules(Client *sender, const std::vector<std::string> &msg);
		// int		server(Client *sender, const std::vector<std::string> &msg);
		// int		service(Client *sender, const std::vector<std::string> &msg);
		// int		servlist(Client *sender, const std::vector<std::string> &msg);
		// int		squery(Client *sender, const std::vector<std::string> &msg);
		// int		squit(Client *sender, const std::vector<std::string> &msg);
		// int		setname(Client *sender, const std::vector<std::string> &msg);
		// int		silence(Client *sender, const std::vector<std::string> &msg);
		// int		stats(Client *sender, const std::vector<std::string> &msg);
		// int		summon(Client *sender, const std::vector<std::string> &msg);
		// int		time(Client *sender, const std::vector<std::string> &msg);
		// int		topic(Client *sender, const std::vector<std::string> &msg);
		// int		trace(Client *sender, const std::vector<std::string> &msg);
		// int		uhnames(Client *sender, const std::vector<std::string> &msg);
		int		user(Client *sender, const std::vector<std::string> &msg);
		// int		userhost(Client *sender, const std::vector<std::string> &msg);
		// int		userip(Client *sender, const std::vector<std::string> &msg);
		// int		users(Client *sender, const std::vector<std::string> &msg);
		// int		version(Client *sender, const std::vector<std::string> &msg);
		// int		wallops(Client *sender, const std::vector<std::string> &msg);
		// int		watch(Client *sender, const std::vector<std::string> &msg);
		// int		who(Client *sender, const std::vector<std::string> &msg);
		// int		whois(Client *sender, const std::vector<std::string> &msg);
		

	private:
		std::vector<Client *>			_clients;
		std::string						_password;
		std::string						_hostname;
		Socket							_socket;
		fd_set							_rfds;
		fd_set							_wfds;
		static char						_buffer[1024];
		static std::string 				_hello;
		userCmds					 	_cmd_list;
		std::map<std::string, User *>	_user_list;
		std::map<std::string, std::string> _msg_list;
};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

