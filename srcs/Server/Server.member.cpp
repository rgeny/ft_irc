/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/13 12:50:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Command.hpp"
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
			this->_clients.insert(std::make_pair(new Client("Mr Satan"));
		}
		else
		{
			for (int i = 0; i < this->_clients.size(); i++)
			{
				if (this->_clients[i]->get_socket().is_set(&this->_rfds))
				{
					std::cout	<< "nickname: "
								<< this->_clients[i]->nickname.get()
								<< std::endl;
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
							cmd.parse(buf[j], this->_clients[i]);
							for (int k = 0; k < cmd.cmd.get().size(); k++)
								std::cout	<< cmd.cmd.get()[k] << std::endl;
							this->_clients[i]->get_socket().send(buf[j]);
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

  _cmd_list["ADMIN"] = &Server::admin;
  _cmd_list["AWAY"] = &Server::away;
  _cmd_list["CNOTICE"] = &Server::cnotice;
  _cmd_list["CPRIVMSG"] = &Server::cprivmsg;
  _cmd_list["CONNECT"] = &Server::connect;
  _cmd_list["DIE"] = &Server::die;
  _cmd_list["ENCAP"] = &Server::encap;
  _cmd_list["ERROR"] = &Server::error;
  _cmd_list["HELP"] = &Server::help;
  _cmd_list["INFO"] = &Server::info;
  _cmd_list["INVITE"] = &Server::invite;
  _cmd_list["ISON"] = &Server::ison;
  _cmd_list["JOIN"] = &Server::join;
  _cmd_list["KICK"] = &Server::kick;
  _cmd_list["KILL"] = &Server::kill;
  _cmd_list["KNOCK"] = &Server::knock;
  _cmd_list["LINKS"] = &Server::links;
  _cmd_list["LIST"] = &Server::list;
  _cmd_list["LUSERS"] = &Server::lusers;
  _cmd_list["MODE"] = &Server::mode;
  _cmd_list["MOTD"] = &Server::motd;
  _cmd_list["NAMES"] = &Server::names;
  _cmd_list["NAMESX"] = &Server::namesx;
  _cmd_list["NICK"] = &Server::nick;
  _cmd_list["NOTICE"] = &Server::notice;
  _cmd_list["OPER"] = &Server::oper;
  _cmd_list["PART"] = &Server::part;
  _cmd_list["PASS"] = &Server::pass;
  _cmd_list["PING"] = &Server::ping;
  _cmd_list["PONG"] = &Server::pong;
  _cmd_list["PRIVMSG"] = &Server::privmsg;
  _cmd_list["QUIT"] = &Server::quit;
  _cmd_list["REHASH"] = &Server::rehash;
  _cmd_list["RULES"] = &Server::rules;
  _cmd_list["SERVER"] = &Server::server;
  _cmd_list["SERVICE"] = &Server::service;
  _cmd_list["SERVLIST"] = &Server::servlist;
  _cmd_list["SQUERY"] = &Server::squery;
  _cmd_list["SQUIT"] = &Server::squit;
  _cmd_list["SETNAME"] = &Server::setname;
  _cmd_list["SILENCE"] = &Server::silence;
  _cmd_list["STATS"] = &Server::stats;
  _cmd_list["SUMMON"] = &Server::summon;
  _cmd_list["TIME"] = &Server::time;
  _cmd_list["TOPIC"] = &Server::topic;
  _cmd_list["TRACE"] = &Server::trace;
  _cmd_list["UHNAMES"] = &Server::uhnames;
  _cmd_list["USER"] = &Server::user;
  _cmd_list["USERHOST"] = &Server::userhost;
  _cmd_list["USERIP"] = &Server::userip;
  _cmd_list["USERS"] = &Server::users;
  _cmd_list["VERSION"] = &Server::version;
  _cmd_list["WALLOPS"] = &Server::wallops;
  _cmd_list["WATCH"] = &Server::watch;
  _cmd_list["WHO"] = &Server::who;
  _cmd_list["WHOIS"] = &Server::whois;
}