/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:13:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/22 14:57:40 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include "User.hpp"

# include "Message.hpp"
# include "Accessor.hpp"
# include "ircserv.hpp"

class Command
{
	public:
		typedef int (Command::*CommandPointer)	(std::vector<std::string> & msg);
		typedef std::map<std::string, CommandPointer>	CmdsFct;
		typedef std::vector<std::vector<std::string> >	ClientCmds;


//		Accessor<std::vector<std::string> >	tokens;

		Command		(std::vector<User *> & users);
		Command		(Command & src);
		~Command	(void);

		Command &	operator=	(Command & src);

void	main		(Client * client
							,std::string & arg);
	private:
		static CmdsFct		_cmds_fct;

		std::vector<User *>	&	_users;

		ClientCmds		_client_cmds;
		Client *		_client;
		bool			_is_user;

//		Command	(void);

		bool	_get_user_type	(void);
		void	_parse			(std::string & cmd);
		void	_check_cmd		(std::vector<std::string> & cmd);

		int		_nick			(std::vector<std::string> & msg);
		int		_user			(std::vector<std::string> & msg);

		void	_init_cmd_fct	(void);
};

std::ostream &	operator<<	(std::ostream & os
							,Command & src);
#endif

// void		find_replace_tags(std::string & data, std::string toSearch, std::string replaceStr);

// int		admin(Client *sender, const std::vector<std::string> &msg);
// int		away(Client *sender, const std::vector<std::string> &msg);
// int		cap(Client *sender, std::vector<std::string> &msg);
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
// int		userhost(Client *sender, const std::vector<std::string> &msg);
// int		userip(Client *sender, const std::vector<std::string> &msg);
// int		users(Client *sender, const std::vector<std::string> &msg);
// int		version(Client *sender, const std::vector<std::string> &msg);
// int		wallops(Client *sender, const std::vector<std::string> &msg);
// int		watch(Client *sender, const std::vector<std::string> &msg);
// int		who(Client *sender, const std::vector<std::string> &msg);
// int		whois(Client *sender, const std::vector<std::string> &msg);
