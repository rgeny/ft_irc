/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:41:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 22:53:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::UserCmds	Command::_cmd_list;

Command:: Command	(void)
{
	std::cout	<< "Command dfl constructor."
				<< std::endl;
	if (Command::_cmd_list.size() == 0)
	{
//		Command::_cmd_list["ADMIN"] = &Command::admin;
//		Command::_cmd_list["AWAY"] = &Command::away;
//		Command::_cmd_list["CAP"] = &Command::cap;
//		Command::_cmd_list["CNOTICE"] = &Command::cnotice;
//		Command::_cmd_list["CPRIVMSG"] = &Command::cprivmsg;
//		Command::_cmd_list["CONNECT"] = &Command::connect;
//		Command::_cmd_list["DIE"] = &Command::die;
//		Command::_cmd_list["ENCAP"] = &Command::encap;
//		Command::_cmd_list["ERROR"] = &Command::error;
//		Command::_cmd_list["HELP"] = &Command::help;
//		Command::_cmd_list["INFO"] = &Command::info;
//		Command::_cmd_list["INVITE"] = &Command::invite;
//		Command::_cmd_list["ISON"] = &Command::ison;
//		Command::_cmd_list["JOIN"] = &Command::join;
//		Command::_cmd_list["KICK"] = &Command::kick;
//		Command::_cmd_list["KILL"] = &Command::kill;
//		Command::_cmd_list["KNOCK"] = &Command::knock;
//		Command::_cmd_list["LINKS"] = &Command::links;
//		Command::_cmd_list["LIST"] = &Command::list;
//		Command::_cmd_list["LUSERS"] = &Command::lusers;
//		Command::_cmd_list["MODE"] = &Command::mode;
//		Command::_cmd_list["MOTD"] = &Command::motd;
//		Command::_cmd_list["NAMES"] = &Command::names;
//		Command::_cmd_list["NAMESX"] = &Command::namesx;
		Command::_cmd_list["NICK"] = &Command::nick;
//		Command::_cmd_list["NOTICE"] = &Command::notice;
//		Command::_cmd_list["OPER"] = &Command::oper;
//		Command::_cmd_list["PART"] = &Command::part;
//		Command::_cmd_list["PASS"] = &Command::pass;
//		Command::_cmd_list["PING"] = &Command::ping;
//		Command::_cmd_list["PONG"] = &Command::pong;
//		Command::_cmd_list["PRIVMSG"] = &Command::privmsg;
//		Command::_cmd_list["QUIT"] = &Command::quit;
//		Command::_cmd_list["REHASH"] = &Command::rehash;
//		Command::_cmd_list["RULES"] = &Command::rules;
//		Command::_cmd_list["SERVER"] = &Command::server;
//		Command::_cmd_list["SERVICE"] = &Command::service;
//		Command::_cmd_list["SERVLIST"] = &Command::servlist;
//		Command::_cmd_list["SQUERY"] = &Command::squery;
//		Command::_cmd_list["SQUIT"] = &Command::squit;
//		Command::_cmd_list["SETNAME"] = &Command::setname;
//		Command::_cmd_list["SILENCE"] = &Command::silence;
//		Command::_cmd_list["STATS"] = &Command::stats;
//		Command::_cmd_list["SUMMON"] = &Command::summon;
//		Command::_cmd_list["TIME"] = &Command::time;
//		Command::_cmd_list["TOPIC"] = &Command::topic;
//		Command::_cmd_list["TRACE"] = &Command::trace;
//		Command::_cmd_list["UHNAMES"] = &Command::uhnames;
		Command::_cmd_list["USER"] = &Command::user;
//		Command::_cmd_list["USERHOST"] = &Command::userhost;
//		Command::_cmd_list["USERIP"] = &Command::userip;
//		Command::_cmd_list["USERS"] = &Command::users;
//		Command::_cmd_list["VERSION"] = &Command::version;
//		Command::_cmd_list["WALLOPS"] = &Command::wallops;
//		Command::_cmd_list["WATCH"] = &Command::watch;
//		Command::_cmd_list["WHO"] = &Command::who;
//		Command::_cmd_list["WHOIS"] = &Command::whois;
	}
}

Command:: Command	(Command & src)
{
	(void)src;
	std::cout	<< "Command cpy constructor."
				<< std::endl;
}

Command::~Command	(void)
{
	std::cout	<< "Command destructor."
				<< std::endl;
}


