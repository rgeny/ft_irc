/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/16 09:51:48 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Command.hpp"
#include "Message.hpp"
#include "User.hpp"
#include "ircserv.hpp"

#include <cstring>
std::string Server::_hello = "Welcome to the Server\n";
char		Server::_buffer[1024] = "";

void	Server::main			(void)
{
	while (true)
	{
		this->init_rfds();
		this->_socket.select(&this->_rfds, &this->_wfds);
		if (FD_ISSET(STDIN_FILENO, &this->_rfds))
			return ;
		else if (this->_socket.is_set(&this->_rfds))
		{
			std::cout	<< "1\n";
			this->_clients.push_back(new Client("Mr Satan"));
		}
		else
		{
			for (int i = 0; i < this->_clients.size(); i++)
			{
				if (this->_clients[i]->get_socket().is_set(&this->_rfds))
				{
					//std::cout	<< "nickname: "
					//			<< this->_clients[i]->nickname.get()
					//			<< std::endl;
					std::vector<std::string>	buf;
					int			n = this->_clients[i]->get_socket().receive(buf);
					if (n == 0)
						this->del_client(i);
					else
					{
						std::cout	<< buf.size()
									<< std::endl;
						for (int j = 0; j < buf.size(); j++)
						{
							std::cout	<< "buf[" 
										<< j
										<< "] : "
										<< buf[j]
										<< std::endl;
							Command cmd;
							cmd.parse(buf[j], this->_clients[i], 0);
							std::cout << "size of tokens: " << cmd.tokens.get().size() << std::endl;
							check_cmd(this->_clients[i], cmd.tokens.get());
							//for (int k = 0; k < cmd.tokens.get().size(); k++)
							//	std::cout	<< cmd.tokens.get()[k] << std::endl;
							// this->_clients[i]->get_socket().send(buf[j]);
						}
					}
				}
			}
		}
	}
}

void	Server::init_rfds		(void)
{
	FD_ZERO	(&this->_rfds);
	FD_SET	(STDIN_FILENO
			,&this->_rfds);
	this->_socket.add_in_fds(&this->_rfds);
	for (int i = 0; i < this->_clients.size(); i++)
	{
		this->_clients[i]->get_socket().add_in_fds(&this->_rfds);
	}
}


void	Server::del_client		(int i)
{
	delete this->_clients[i];
	this->_clients.erase(this->_clients.begin() + i);
}

void Server::init_cmd_list( void )
{

//   _cmd_list["ADMIN"] = &Server::admin;
//   _cmd_list["AWAY"] = &Server::away;
	 _cmd_list["CAP"] = &Server::cap;
//   _cmd_list["CNOTICE"] = &Server::cnotice;
//   _cmd_list["CPRIVMSG"] = &Server::cprivmsg;
//   _cmd_list["CONNECT"] = &Server::connect;
//   _cmd_list["DIE"] = &Server::die;
//   _cmd_list["ENCAP"] = &Server::encap;
//   _cmd_list["ERROR"] = &Server::error;
//   _cmd_list["HELP"] = &Server::help;
//   _cmd_list["INFO"] = &Server::info;
//   _cmd_list["INVITE"] = &Server::invite;
//   _cmd_list["ISON"] = &Server::ison;
//   _cmd_list["JOIN"] = &Server::join;
//   _cmd_list["KICK"] = &Server::kick;
//   _cmd_list["KILL"] = &Server::kill;
//   _cmd_list["KNOCK"] = &Server::knock;
//   _cmd_list["LINKS"] = &Server::links;
//   _cmd_list["LIST"] = &Server::list;
//   _cmd_list["LUSERS"] = &Server::lusers;
//   _cmd_list["MODE"] = &Server::mode;
//   _cmd_list["MOTD"] = &Server::motd;
//   _cmd_list["NAMES"] = &Server::names;
//   _cmd_list["NAMESX"] = &Server::namesx;
	 _cmd_list["NICK"] = &Server::nick;
//   _cmd_list["NOTICE"] = &Server::notice;
//   _cmd_list["OPER"] = &Server::oper;
//   _cmd_list["PART"] = &Server::part;
//   _cmd_list["PASS"] = &Server::pass;
//   _cmd_list["PING"] = &Server::ping;
//   _cmd_list["PONG"] = &Server::pong;
//   _cmd_list["PRIVMSG"] = &Server::privmsg;
//   _cmd_list["QUIT"] = &Server::quit;
//   _cmd_list["REHASH"] = &Server::rehash;
//   _cmd_list["RULES"] = &Server::rules;
//   _cmd_list["SERVER"] = &Server::server;
//   _cmd_list["SERVICE"] = &Server::service;
//   _cmd_list["SERVLIST"] = &Server::servlist;
//   _cmd_list["SQUERY"] = &Server::squery;
//   _cmd_list["SQUIT"] = &Server::squit;
//   _cmd_list["SETNAME"] = &Server::setname;
//   _cmd_list["SILENCE"] = &Server::silence;
//   _cmd_list["STATS"] = &Server::stats;
//   _cmd_list["SUMMON"] = &Server::summon;
//   _cmd_list["TIME"] = &Server::time;
//   _cmd_list["TOPIC"] = &Server::topic;
//   _cmd_list["TRACE"] = &Server::trace;
//   _cmd_list["UHNAMES"] = &Server::uhnames;
  _cmd_list["USER"] = &Server::user;
//   _cmd_list["USERHOST"] = &Server::userhost;
//   _cmd_list["USERIP"] = &Server::userip;
//   _cmd_list["USERS"] = &Server::users;
//   _cmd_list["VERSION"] = &Server::version;
//   _cmd_list["WALLOPS"] = &Server::wallops;
//   _cmd_list["WATCH"] = &Server::watch;
//   _cmd_list["WHO"] = &Server::who;
//   _cmd_list["WHOIS"] = &Server::whois;
}

void Server::check_cmd(Client *sender, std::vector<std::string> cmd)
{
	std::cout << "command: " << cmd[0] << " - caseproof version: " << case_proof(cmd[0]) << std::endl; 
	userCmds::iterator it = _cmd_list.find(case_proof(cmd[0]));
	if (it != _cmd_list.end())
	{
		std::cout << "COMMAND FOUND" << std::endl;
		(this->*(it->second))(sender, cmd);
	}
	else
		std::cout << "UNKNOWN COMMAND" << std::endl;
		
}

int	Server::cap(Client *sender, const std::vector<std::string> &cmd)
{
	bool	tmp = true;
	if (cmd.size() > 1)
		std::cout << "cmd.size(): " << cmd.size() << " - case_proof(cmd[1]): " << case_proof(cmd[1]) << std::endl;
	if (cmd.size() > 1 && sender->get_socket().cap.get() == false && (case_proof(cmd[1]).compare("REQ") == 0 || case_proof(cmd[1]).compare("LS") == 0))
	{
		std::cout << "CAP ACTIVATED!!" << std::endl;
		sender->get_socket().cap.set(tmp);
	}
	return (0);
}

int	Server::nick(Client *sender, const std::vector<std::string> &cmd)
{
	if (sender->get_socket().cap.get() == true)
	{
		std::cout << "ACCEPTED IN CAP SECTION" << std::endl;
		// First we check if the user is already registered 
		// => if he is, then it means he wants to swap nickname
		if (sender->get_user().nickname.get() != "anonymous")
		{
			std::cout << "CHANGE OF NICK!!" << std::endl;
		}
		// if the user is not registered on the server yet, he needs 
		// to be welcomed for the 1st time on the server
		else if (cmd.size() > 1)
		{
			std::string cmd1(cmd[1]);
			r_trim(cmd1);
			if (_user_list.find(cmd1) == _user_list.end())
			{
				sender->get_user().nickname.set(cmd1);
				_user_list[cmd1] = &sender->get_user(); // we update the user_list with the new nickname / user
			}

			std::cout << "NICKNAME SET: " << sender->get_user().nickname.get() << std::endl;
			std::cout << "TEST\n";
		}
		return 0;
	}
	return (-1);
}

int	Server::user(Client *sender, const std::vector<std::string> &cmd)
{
	std::cout << "Je suis dans la commande user - " << sender->get_user().nickname.get() << std::endl;
	if (sender->get_socket().cap.get() == true && sender->get_user().nickname.get() != "anonymous")
	{
		std::cout << "cmd.size(): " << cmd.size() << std::endl;
		if (cmd.size() > 4)
		{	
			std::string u(cmd[1]);
			std::string tmp = "";
			User *cur_user = &sender->get_user();
			cur_user->username.set(u);
			std::cout << "cmd[1]: " << cmd[1] << std::endl;
			std::cout << "USERNAME SET:" << cur_user->username.get() << std::endl;
			for (int i = 5; i < cmd.size(); i++)
				tmp += cmd[i];
			cur_user->realname.set(tmp);
			std::cout << "REALNAME SET:" << cur_user->realname.get() << std::endl;
			if (_user_list.find(cmd[1]) == _user_list.end())
				_user_list[cmd[1]] = &sender->get_user(); // we update the user_list with the new nickname / user
			Message reply(":"+_hostname, cmd[1], RPL_WELCOME, WELCOME_MSG + sender->get_user().fci());
			std::string final_msg = reply.aggreg();
			std::cout << "Reply sent before: " << final_msg << std::endl;
			sender->get_socket().send(final_msg);
			//std::cout << "WELCOME TO THIS IRC SERVER!!" << std::endl;
		}
		return 0;
	}
	return (-1);
}