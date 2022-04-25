/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:13:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 21:30:54 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP
# define CLOSE "Closing"
# define BADPASSWD "Bad password"

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include "User.hpp"

# include "Message.hpp"
# include "ircserv.hpp"

# include "e_error.hpp"


class Command
	:virtual protected Message
{
	public:
		typedef e_error (Command::*CommandPointer)	(std::vector<std::string> & msg);
		typedef std::map<std::string, CommandPointer>	CmdsFct;
//		typedef std::vector<std::vector<std::string> >	ClientCmds;
//		typedef std::vector<User *>						USERS_LIST;
//		typedef USERS_LIST::iterator					USERS_IT;

		Command		(void);
		Command		(Command & src);
		~Command	(void);

		Command &	operator=	(Command & src);

		void	main		(void);
	private:
		static CmdsFct		_cmds_fct;

//		ClientCmds		_client_cmds;
//		Client *		_client;
		bool			_is_user;

//		Command	(void);

		bool	_get_user_type		(void);
		void	_parse				(void);
		void	_check_cmd			(std::vector<std::string> & cmd);
		bool	_nick_already_used	(std::string & nickname) const;
//		void	_check_error		(e_error code);

		e_error		_pass			(std::vector<std::string> & msg);
		e_error		_nick			(std::vector<std::string> & msg);
		e_error		_user			(std::vector<std::string> & msg);
		e_error		_ping			(std::vector<std::string> & msg);

		void	_init_cmd_fct	(void);
};

std::ostream &	operator<<	(std::ostream & os
							,Command & src);
#endif

// void		find_replace_tags(std::string & data, std::string toSearch, std::string replaceStr);

// e_error		admin(Client *sender, const std::vector<std::string> &msg);
// e_error		away(Client *sender, const std::vector<std::string> &msg);
// e_error		cap(Client *sender, std::vector<std::string> &msg);
// e_error		cnotice(Client *sender, const std::vector<std::string> &msg);
// e_error		cprivmsg(Client *sender, const std::vector<std::string> &msg);
// e_error		connect(Client *sender, const std::vector<std::string> &msg);
// e_error		die(Client *sender, const std::vector<std::string> &msg);
// e_error		encap(Client *sender, const std::vector<std::string> &msg);
// e_error		error(Client *sender, const std::vector<std::string> &msg);
// e_error		help(Client *sender, const std::vector<std::string> &msg);
// e_error		info(Client *sender, const std::vector<std::string> &msg);
// e_error		invite(Client *sender, const std::vector<std::string> &msg);
// e_error		ison(Client *sender, const std::vector<std::string> &msg);
// e_error		join(Client *sender, const std::vector<std::string> &msg);
// e_error		kick(Client *sender, const std::vector<std::string> &msg);
// e_error		kill(Client *sender, const std::vector<std::string> &msg);
// e_error		knock(Client *sender, const std::vector<std::string> &msg);
// e_error		links(Client *sender, const std::vector<std::string> &msg);
// e_error		list(Client *sender, const std::vector<std::string> &msg);
// e_error		lusers(Client *sender, const std::vector<std::string> &msg);
// e_error		mode(Client *sender, const std::vector<std::string> &msg);
// e_error		motd(Client *sender, const std::vector<std::string> &msg);
// e_error		names(Client *sender, const std::vector<std::string> &msg);
// e_error		namesx(Client *sender, const std::vector<std::string> &msg);
// e_error		notice(Client *sender, const std::vector<std::string> &msg);
// e_error		oper(Client *sender, const std::vector<std::string> &msg);
// e_error		part(Client *sender, const std::vector<std::string> &msg);
// e_error		pass(Client *sender, const std::vector<std::string> &msg);
// e_error		ping(Client *sender, const std::vector<std::string> &msg);
// e_error		pong(Client *sender, const std::vector<std::string> &msg);
// e_error		privmsg(Client *sender, const std::vector<std::string> &msg);
// e_error		quit(Client *sender, const std::vector<std::string> &msg);
// e_error		rehash(Client *sender, const std::vector<std::string> &msg);
// e_error		rules(Client *sender, const std::vector<std::string> &msg);
// e_error		server(Client *sender, const std::vector<std::string> &msg);
// e_error		service(Client *sender, const std::vector<std::string> &msg);
// e_error		servlist(Client *sender, const std::vector<std::string> &msg);
// e_error		squery(Client *sender, const std::vector<std::string> &msg);
// e_error		squit(Client *sender, const std::vector<std::string> &msg);
// e_error		setname(Client *sender, const std::vector<std::string> &msg);
// e_error		silence(Client *sender, const std::vector<std::string> &msg);
// e_error		stats(Client *sender, const std::vector<std::string> &msg);
// e_error		summon(Client *sender, const std::vector<std::string> &msg);
// e_error		time(Client *sender, const std::vector<std::string> &msg);
// e_error		topic(Client *sender, const std::vector<std::string> &msg);
// e_error		trace(Client *sender, const std::vector<std::string> &msg);
// e_error		uhnames(Client *sender, const std::vector<std::string> &msg);
// e_error		userhost(Client *sender, const std::vector<std::string> &msg);
// e_error		userip(Client *sender, const std::vector<std::string> &msg);
// e_error		users(Client *sender, const std::vector<std::string> &msg);
// e_error		version(Client *sender, const std::vector<std::string> &msg);
// e_error		wallops(Client *sender, const std::vector<std::string> &msg);
// e_error		watch(Client *sender, const std::vector<std::string> &msg);
// e_error		who(Client *sender, const std::vector<std::string> &msg);
// e_error		whois(Client *sender, const std::vector<std::string> &msg);
