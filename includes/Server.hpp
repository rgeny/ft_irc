/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 17:37:48 by abesombe         ###   ########.fr       */
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
# include "User.hpp"


class Server
{
	
	typedef int (Server::*UserCommandPointer)(User *, std::vector<std::string> & message);
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
		void 	check_cmd(User *sender, std::vector<std::string> tokens);

		// void find_replace_tags(std::string & data, std::string toSearch, std::string replaceStr);
		// int		admin(User *sender, const std::vector<std::string> &msg);
		// int		away(User *sender, const std::vector<std::string> &msg);
		int		cap(User *sender, std::vector<std::string> &msg);
		// int		cnotice(User *sender, const std::vector<std::string> &msg);
		// int		cprivmsg(User *sender, const std::vector<std::string> &msg);
		// int		connect(User *sender, const std::vector<std::string> &msg);
		// int		die(User *sender, const std::vector<std::string> &msg);
		// int		encap(User *sender, const std::vector<std::string> &msg);
		// int		error(User *sender, const std::vector<std::string> &msg);
		// int		help(User *sender, const std::vector<std::string> &msg);
		// int		info(User *sender, const std::vector<std::string> &msg);
		// int		invite(User *sender, const std::vector<std::string> &msg);
		// int		ison(User *sender, const std::vector<std::string> &msg);
		// int		join(User *sender, const std::vector<std::string> &msg);
		// int		kick(User *sender, const std::vector<std::string> &msg);
		// int		kill(User *sender, const std::vector<std::string> &msg);
		// int		knock(User *sender, const std::vector<std::string> &msg);
		// int		links(User *sender, const std::vector<std::string> &msg);
		// int		list(User *sender, const std::vector<std::string> &msg);
		// int		lusers(User *sender, const std::vector<std::string> &msg);
		// int		mode(User *sender, const std::vector<std::string> &msg);
		// int		motd(User *sender, const std::vector<std::string> &msg);
		// int		names(User *sender, const std::vector<std::string> &msg);
		// int		namesx(User *sender, const std::vector<std::string> &msg);
		int			nick(User *sender, std::vector<std::string> &msg);
		// int		notice(User *sender, const std::vector<std::string> &msg);
		// int		oper(User *sender, const std::vector<std::string> &msg);
		// int		part(User *sender, const std::vector<std::string> &msg);
		// int		pass(User *sender, const std::vector<std::string> &msg);
		// int		ping(User *sender, const std::vector<std::string> &msg);
		// int		pong(User *sender, const std::vector<std::string> &msg);
		// int		privmsg(User *sender, const std::vector<std::string> &msg);
		// int		quit(User *sender, const std::vector<std::string> &msg);
		// int		rehash(User *sender, const std::vector<std::string> &msg);
		// int		rules(User *sender, const std::vector<std::string> &msg);
		// int		server(User *sender, const std::vector<std::string> &msg);
		// int		service(User *sender, const std::vector<std::string> &msg);
		// int		servlist(User *sender, const std::vector<std::string> &msg);
		// int		squery(User *sender, const std::vector<std::string> &msg);
		// int		squit(User *sender, const std::vector<std::string> &msg);
		// int		setname(User *sender, const std::vector<std::string> &msg);
		// int		silence(User *sender, const std::vector<std::string> &msg);
		// int		stats(User *sender, const std::vector<std::string> &msg);
		// int		summon(User *sender, const std::vector<std::string> &msg);
		// int		time(User *sender, const std::vector<std::string> &msg);
		// int		topic(User *sender, const std::vector<std::string> &msg);
		// int		trace(User *sender, const std::vector<std::string> &msg);
		// int		uhnames(User *sender, const std::vector<std::string> &msg);
		int		user(User *sender, std::vector<std::string> &msg);
		// int		userhost(User *sender, const std::vector<std::string> &msg);
		// int		userip(User *sender, const std::vector<std::string> &msg);
		// int		users(User *sender, const std::vector<std::string> &msg);
		// int		version(User *sender, const std::vector<std::string> &msg);
		// int		wallops(User *sender, const std::vector<std::string> &msg);
		// int		watch(User *sender, const std::vector<std::string> &msg);
		// int		who(User *sender, const std::vector<std::string> &msg);
		// int		whois(User *sender, const std::vector<std::string> &msg);
		
		std::map<std::string, std::string>	get_msg_list(void) const;
		
	private:
		std::vector<User *>			_clients;
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

