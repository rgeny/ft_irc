/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 15:53:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::main	(Client * client
						,std::string & cmd)
{
	this->_client = client;
	this->_is_user = this->_get_user_type();
	this->_parse(cmd);

	ClientCmds::iterator	it	= this->_client_cmds.begin(),
							ite = this->_client_cmds.end();
	while (it != ite)
	{
		this->_check_cmd(*it);
		it++;
	}
}

bool	Command::_get_user_type	(void)
{
	std::vector<User *>::iterator	it	= this->_data._users.begin(),
									ite	= this->_data._users.end();
	while (it != ite)
	{
		if (*it == this->_client)
			return (true);
		it++;
	}
	return (false);
}

void	Command::_parse	(std::string & cmd)
{
	std::vector<std::string>	tmp = split(cmd, "\r\n");

	this->_client_cmds.clear();
	std::vector<std::string>::iterator	it = tmp.begin(),
										ite = tmp.end();
	while (it != ite)
	{
		this->_client_cmds.push_back(split(*it, " "));
		it++;
	}
}

void	Command::_check_cmd	(std::vector<std::string> & cmd)
{
	CmdsFct::iterator	it = this->_cmds_fct.find(case_proof(cmd[0]));
	if (it != this->_cmds_fct.end())
		(this->*(it->second))(cmd);
}

bool	Command::_nick_already_used	(std::string & nickname) const
{
	USERS_LIST	users = this->_data._users;

	for (USERS_IT it = users.begin(), ite = users.end(); it != ite; it++)
	{
		if ((*it)->get_nickname() == nickname)
			return (true);
	}
	return (false);
}

void	Command::_init_cmd_fct	(void)
{
		if (Command::_cmds_fct.size() == 0)
	{
		Command::_cmds_fct[PASS]		= &Command::_pass;
		Command::_cmds_fct[NICK]		= &Command::_nick;
		Command::_cmds_fct[USER]		= &Command::_user;
		Command::_cmds_fct[PING]		= &Command::_ping;
	}
}
//		Command::_cmds_fct[ADMIN]		= &Command::_admin;
//		Command::_cmds_fct[AWAY]		= &Command::_away;
//		Command::_cmds_fct[CAP]			= &Command::_cap;
//		Command::_cmds_fct[CNOTICE]		= &Command::_cnotice;
//		Command::_cmds_fct[CPRIVMSG]	= &Command::_cprivmsg;
//		Command::_cmds_fct[CONNECT]		= &Command::_connect;
//		Command::_cmds_fct[DIE]			= &Command::_die;
//		Command::_cmds_fct[ENCAP]		= &Command::_encap;
//		Command::_cmds_fct[ERROR]		= &Command::_error;
//		Command::_cmds_fct[HELP]		= &Command::_help;
//		Command::_cmds_fct[INFO]		= &Command::_info;
//		Command::_cmds_fct[INVITE]		= &Command::_invite;
//		Command::_cmds_fct[ISON]		= &Command::_ison;
//		Command::_cmds_fct[JOIN]		= &Command::_join;
//		Command::_cmds_fct[KICK]		= &Command::_kick;
//		Command::_cmds_fct[KILL]		= &Command::_kill;
//		Command::_cmds_fct[KNOCK]		= &Command::_knock;
//		Command::_cmds_fct[LINKS]		= &Command::_links;
//		Command::_cmds_fct[LIST]		= &Command::_list;
//		Command::_cmds_fct[LUSERS]		= &Command::_lusers;
//		Command::_cmds_fct[MODE]		= &Command::_mode;
//		Command::_cmds_fct[MOTD]		= &Command::_motd;
//		Command::_cmds_fct[NAMES]		= &Command::_names;
//		Command::_cmds_fct[NAMESX]		= &Command::_namesx;
//		Command::_cmds_fct[NOTICE]		= &Command::_notice;
//		Command::_cmds_fct[OPER]		= &Command::_oper;
//		Command::_cmds_fct[PART]		= &Command::_part;
//		Command::_cmds_fct[PONG]		= &Command::_pong;
//		Command::_cmds_fct[PRIVMSG]		= &Command::_privmsg;
//		Command::_cmds_fct[QUIT]		= &Command::_quit;
//		Command::_cmds_fct[REHASH]		= &Command::_rehash;
//		Command::_cmds_fct[RULES]		= &Command::_rules;
//		Command::_cmds_fct[SERVER]		= &Command::_server;
//		Command::_cmds_fct[SERVICE]		= &Command::_service;
//		Command::_cmds_fct[SERVLIST]	= &Command::_servlist;
//		Command::_cmds_fct[SQUERY]		= &Command::_squery;
//		Command::_cmds_fct[SQUIT]		= &Command::_squit;
//		Command::_cmds_fct[SETNAME]		= &Command::_setname;
//		Command::_cmds_fct[SILENCE]		= &Command::_silence;
//		Command::_cmds_fct[STATS]		= &Command::_stats;
//		Command::_cmds_fct[SUMMON]		= &Command::_summon;
//		Command::_cmds_fct[TIME]		= &Command::_time;
//		Command::_cmds_fct[TOPIC]		= &Command::_topic;
//		Command::_cmds_fct[TRACE]		= &Command::_trace;
//		Command::_cmds_fct[UHNAMES]		= &Command::_uhnames;
//		Command::_cmds_fct[USERHOST]	= &Command::_userhost;
//		Command::_cmds_fct[USERIP]		= &Command::_userip;
//		Command::_cmds_fct[USERS]		= &Command::_users;
//		Command::_cmds_fct[VERSION]		= &Command::_version;
//		Command::_cmds_fct[WALLOPS]		= &Command::_wallops;
//		Command::_cmds_fct[WATCH]		= &Command::_watch;
//		Command::_cmds_fct[WHO]			= &Command::_who;
//		Command::_cmds_fct[WHOIS]		= &Command::_whois;

