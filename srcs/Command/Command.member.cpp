/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 01:53:58 by rgeny            ###   ########.fr       */
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
		std::vector<std::string>::iterator it_token = (*it).begin();
		std::vector<std::string>::iterator ite_token = (*it).end();
		while (it_token != ite_token)
		{
			std::cout << *it_token << std::endl;
			it_token++;
		}
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
//	std::string	tmp;
//	this->tokens = split (cmd_str, " ");
//	this->_user = user;
}

void	Command::_check_cmd	(std::vector<std::string> & cmd)
{
	CmdsFct::iterator	it = this->_cmds_fct.find(case_proof(cmd[0]));
	if (it != this->_cmds_fct.end())
		(this->*(it->second))(cmd);
}

int		Command::_nick	(std::vector<std::string> & cmd)
{
	Message reply;

	if (cmd.size() <= 1)
	{
		reply.add_arg(cmd[0]);
		std::string final_msg = reply.forge("127.0.0.1", ERR_NONICKNAMEGIVEN);
		this->_client->add_to_queue(final_msg);
		return (-1);
	}
	else
	{
		reply.add_arg(cmd[1]);
		std::cout << "nickname: " << cmd[1] << std::endl;
		if (cmd.size() > 1)
		{
			if (this->_client->set_nickname(cmd[1]) == false)
			{
				std::string final_msg = reply.forge("127.0.0.1", ERR_ERRONEUSNICKNAME);
				std::cout	 << "msg forge : " 
							<< final_msg << "\n";
				this->_client->add_to_queue(final_msg);
				return (-1);
			}
//		if (this->_client->get_user().is_nick_valid(cmd[1]) == false)
//		{
//			std::string final_msg = reply.forge("127.0.0.1", ERR_ERRONEUSNICKNAME, _msg_list);
//			this->_client->add_to_queue(final_msg);
//			return (-1);
//		}
//		if (this->_client->get_nickname() != "anonymous")
//		{
//			std::cout << "CHANGE OF NICK!!" << std::endl;
//		}
//		else if (cmd.size() > 1)
//		{
//			if (_user_list.find(cmd[1]) == _user_list.end())
//			{
//				std::cout << "I am in\n";
//				this->_client->get_user().nickname.set(cmd[1]);
//				_user_list[cmd[1]] = &this->_client->get_user(); // we update the user_list with the new nickname / user
//			}

			std::cout << "NICKNAME SET: " << this->_client->get_nickname() << std::endl;

		}
		return (0);
	}
	return (-1);
}

int		Command::_user	(std::vector<std::string> & cmd)
{
	Message reply;

	if (this->_client->get_nickname() != "anonymous")
	{
		if (cmd.size() > 4)
		{
			std::string u(cmd[1]);
			std::string tmp = "";
			User & cur_user = static_cast<User &>(*this->_client);
			cur_user.set_username(u);
			for (size_t i = 5; i < cmd.size(); i++)
				tmp += cmd[i];
			cur_user.set_realname(tmp);
			reply.set_receiver(this->_client->get_nickname());
//			if (_user_list.find(cmd[1]) == _user_list.end())
//				_user_list[cmd[1]] = &this->_client->get_user();
//			reply.add_arg(this->_client->get_user().fci());
			reply.add_arg(cur_user.get_nickname() + "!" + cur_user.get_username() + "@127.0.0.1");

//			std::string	final_msg = this->_msg.main(this->_client, RPL_WELCOME);

			std::string final_msg = reply.forge(":127.0.0.1", RPL_WELCOME);
			this->_client->add_to_queue(final_msg);
		}
		return 0;
	}
	return (-1);
}

int		Command::_ping	(std::vector<std::string> & cmd)
{
	if (cmd.size() > 1)
	{
		std::string	final_msg = "PONG ";
		final_msg += this->_client->get_nickname() + "\r\n";
		this->_client->add_to_queue(final_msg);
	}
	return (0);
}

void	Command::_init_cmd_fct	(void)
{
		if (Command::_cmds_fct.size() == 0)
	{
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
//		Command::_cmds_fct[PASS]		= &Command::_pass;
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

