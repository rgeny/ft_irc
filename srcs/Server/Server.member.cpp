/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/20 12:51:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Command.hpp"
#include "Message.hpp"
#include "User.hpp"
#include "ircserv.hpp"
#define WAITING_FOR_CAP_LS 0
#define WAITING_FOR_CAP_END 1
#define CAP_CYCLE_TERMINATED 2

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
			for (size_t i = 0; i < this->_clients.size(); i++)
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
						for (size_t j = 0; j < buf.size(); j++)
						{
							std::cout	<< "buf[" 
										<< j
										<< "] : "
										<< buf[j]
										<< std::endl;
							Command cmd;
							cmd.parse(buf[j], this->_clients[i]);
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
	for (size_t i = 0; i < this->_clients.size(); i++)
	{
		this->_clients[i]->get_socket().add_in_fds(&this->_rfds);
	}
}


void	Server::del_client(int i)
{
	delete this->_clients[i];
	this->_clients.erase(this->_clients.begin() + i);
}

void Server::init_msg_list( void )
{
	_msg_list["001"] = "Welcome to the Internet Relay Network <fullclientidentifier>";
	_msg_list["002"] = "Your host is <servername>, running version <ver>";
	_msg_list["003"] = "This server was created <date>";
	_msg_list["004"] = "<servername> <version> <available user modes> <available channel modes>";
	_msg_list["005"] = "Try server <server name>, port <port number>";
	_msg_list["200"] = "Link <version & debug level> <destination> <next server> V<protocol version> <link uptime in seconds> <backstream sendq> <upstream sendq>";
	_msg_list["201"] = "Try. <class> <server>";
	_msg_list["202"] = "H.S. <class> <server>";
	_msg_list["203"] = "???? <class> [<client IP address in dot form>]";
	_msg_list["204"] = "Oper <class> <nick>";
	_msg_list["205"] = "User <class> <nick>";
	_msg_list["206"] = "Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> V<protocol version>";
	_msg_list["207"] = "Service <class> <name> <type> <active type>";
	_msg_list["208"] = "<newtype> 0 <client name>";
	_msg_list["209"] = "Class <class> <count>";
	_msg_list["211"] = "<linkname> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>";
	_msg_list["212"] = "<command> <count> <byte count> <remote count>";
	_msg_list["219"] = "<stats letter> :End of STATS report";
	_msg_list["221"] = "<user mode string>";
	_msg_list["234"] = "<name> <server> <mask> <type> <hopcount> <info>";
	_msg_list["235"] = "<mask> <type> :End of service listing";
	_msg_list["242"] = ":Server Up %d days %d:%02d:%02d";
	_msg_list["243"] = "O <hostmask> * <name>";
	_msg_list["251"] = ":There are <integer> users and <integer> services on <integer> servers";
	_msg_list["252"] = "<integer> :operator(s) online";
	_msg_list["253"] = "<integer> :unknown connection(s)";
	_msg_list["254"] = "<integer> :channels formed";
	_msg_list["255"] = ":I have <integer> clients and <integer> servers";
	_msg_list["256"] = "<server> :Administrative info";
	_msg_list["257"] = ":<admin info>";
	_msg_list["258"] = ":<admin info>";
	_msg_list["259"] = ":<admin info>";
	_msg_list["261"] = "File <logfile> <debug level>";
	_msg_list["262"] = "<server name> <version & debug level> :End of TRACE";
	_msg_list["263"] = "<command> :Please wait a while and try again.";
	_msg_list["301"] = "<nick> :<away message>";
	_msg_list["302"] = ":*1<reply> *( " " <reply> )";
	_msg_list["303"] = ":*1<nick> *( " " <nick> )";
	_msg_list["305"] = ":You are no longer marked as being away";
	_msg_list["306"] = ":You have been marked as being away";
	_msg_list["311"] = "<nick> <user> <host> * :<real name>";
	_msg_list["312"] = "<nick> <server> :<server info>";
	_msg_list["313"] = "<nick> :is an IRC operator";
	_msg_list["314"] = "<nick> <user> <host> * :<real name>";
	_msg_list["315"] = "<name> :End of WHO list";
	_msg_list["317"] = "<nick> <integer> :seconds idle";
	_msg_list["318"] = "<nick> :End of WHOIS list";
	_msg_list["319"] = "<nick> :*( ( '@' / '+' ) <channel> " " )";
	_msg_list["322"] = "<channel> <# visible> :<topic>";
	_msg_list["323"] = ":End of LIST";
	_msg_list["324"] = "<channel> <mode> <mode params>";
	_msg_list["325"] = "<channel> <nickname>";
	_msg_list["331"] = "<channel> :No topic is set";
	_msg_list["332"] = "<channel> :<topic>";
	_msg_list["341"] = "<channel> <nick>";
	_msg_list["342"] = "<user> :Summoning user to IRC";
	_msg_list["346"] = "<channel> <invitemask>";
	_msg_list["347"] = "<channel> :End of channel invite list";
	_msg_list["348"] = "<channel> <exceptionmask>";
	_msg_list["349"] = "<channel> :End of channel exception list";
	_msg_list["351"] = "<version>.<debuglevel> <server> :<comments>";
	_msg_list["352"] = "<channel> <user> <host> <server> <nick> ( 'H' / 'G' > ['*'] [ ( '@' / '+' ) ] :<hopcount> <real name>";
	_msg_list["353"] = "( '=' / '*' / '@' ) <channel> :[ '@' / '+' ] <nick> *( " " [ '@' / '+' ] <nick> )";
	_msg_list["364"] = "<mask> <server> :<hopcount> <server info>";
	_msg_list["365"] = "<mask> :End of LINKS list";
	_msg_list["366"] = "<channel> :End of NAMES list";
	_msg_list["367"] = "<channel> <banmask>";
	_msg_list["368"] = "<channel> :End of channel ban list";
	_msg_list["369"] = "<nick> :End of WHOWAS";
	_msg_list["371"] = ":<string>";
	_msg_list["372"] = ":- <text>";
	_msg_list["374"] = ":End of INFO list";
	_msg_list["375"] = ":- <server> Message of the day - ";
	_msg_list["376"] = ":End of MOTD command";
	_msg_list["381"] = ":You are now an IRC operator";
	_msg_list["382"] = "<config file> :Rehashing";
	_msg_list["383"] = "You are service <servicename>";
	_msg_list["391"] = "<server> :<string showing server's local time>";
	_msg_list["392"] = ":UserID Terminal Host";
	_msg_list["393"] = ":<username> <ttyline> <hostname>";
	_msg_list["394"] = ":End of users";
	_msg_list["395"] = ":Nobody logged in";
	_msg_list["401"] = "<nickname> :No such nick/channel";
	_msg_list["402"] = "<server name> :No such server";
	_msg_list["403"] = "<channel name> :No such channel";
	_msg_list["404"] = "<channel name> :Cannot send to channel";
	_msg_list["405"] = "<channel name> :You have joined too many channels";
	_msg_list["406"] = "<nickname> :There was no such nickname";
	_msg_list["407"] = "<target> :<error code> recipients. <abort message>";
	_msg_list["408"] = "<service name> :No such service";
	_msg_list["409"] = ":No origin specified";
	_msg_list["411"] = ":No recipient given (<command>)";
	_msg_list["412"] = ":No text to send";
	_msg_list["413"] = "<mask> :No toplevel domain specified";
	_msg_list["414"] = "<mask> :Wildcard in toplevel domain";
	_msg_list["415"] = "<mask> :Bad Server/host mask";
	_msg_list["421"] = "<command> :Unknown command";
	_msg_list["422"] = ":MOTD File is missing";
	_msg_list["423"] = "<server> :No administrative info available";
	_msg_list["424"] = ":File error doing <file op> on <file>";
	_msg_list["431"] = ":No nickname given";
	_msg_list["432"] = "<nick> :Erroneous nickname";
	_msg_list["433"] = "<nick> :Nickname is already in use";
	_msg_list["436"] = "<nick> :Nickname collision KILL from <user>@<host>";
	_msg_list["437"] = "<nick/channel> :Nick/channel is temporarily unavailable";
	_msg_list["441"] = "<nick> <channel> :They aren't on that channel";
	_msg_list["442"] = "<channel> :You're not on that channel";
	_msg_list["443"] = "<user> <channel> :is already on channel";
	_msg_list["444"] = "<user> :User not logged in";
	_msg_list["445"] = ":SUMMON has been disabled";
	_msg_list["446"] = ":USERS has been disabled";
	_msg_list["451"] = ":You have not registered";
	_msg_list["461"] = "<command> :Not enough parameters";
	_msg_list["462"] = ":Unauthorized command (already registered)";
	_msg_list["463"] = ":Your host isn't among the privileged";
	_msg_list["464"] = ":Password incorrect";
	_msg_list["465"] = ":You are banned from this server";
	_msg_list["467"] = "<channel> :Channel key already set";
	_msg_list["471"] = "<channel> :Cannot join channel (+l)";
	_msg_list["472"] = "<char> :is unknown mode char to me for <channel>";
	_msg_list["473"] = "<channel> :Cannot join channel (+i)";
	_msg_list["474"] = "<channel> :Cannot join channel (+b)";
	_msg_list["475"] = "<channel> :Cannot join channel (+k)";
	_msg_list["476"] = "<channel> :Bad Channel Mask";
	_msg_list["477"] = "<channel> :Channel doesn't support modes";
	_msg_list["478"] = "<channel> <char> :Channel list is full";
	_msg_list["481"] = ":Permission Denied- You're not an IRC operator";
	_msg_list["482"] = "<channel> :You're not channel operator";
	_msg_list["483"] = ":You can't kill a server!";
	_msg_list["484"] = ":Your connection is restricted!";
	_msg_list["485"] = ":You're not the original channel operator";
	_msg_list["491"] = ":No O-lines for your host";
	_msg_list["501"] = ":Unknown MODE flag";
	_msg_list["502"] = ":Cannot change mode for other users";
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
	int	cap_step = WAITING_FOR_CAP_LS;
	std::vector<std::string> args(1, cmd[0]);
	std::string cmd1 = "";
	if (cmd.size() > 1)
	{
		cmd1 = cmd[1];
		r_trim(cmd1);
	}
	if (cmd.size() <= 1)
	{
		Message reply(":"+_hostname, "", ERR_NEEDMOREPARAMS, get_msg(ERR_NEEDMOREPARAMS, &args));
		std::string final_msg = reply.aggreg();
		sender->get_socket().send(final_msg);
		return (-1);
	}
	else if (cmd.size() > 1)
		std::cout << "cmd.size(): " << cmd.size() << " - case_proof(cmd1): " << case_proof(cmd1) << std::endl;
	if (cmd.size() > 1 && sender->get_socket().cap.get() == WAITING_FOR_CAP_LS && (case_proof(cmd1).compare("REQ") == 0 || case_proof(cmd1).compare("LS") == 0))
	{
		std::cout << "CAP LS ACTIVATED!!" << std::endl;
		sender->get_socket().cap.set(cap_step);
	}
	else if (cmd.size() > 1 && sender->get_socket().cap.get() == WAITING_FOR_CAP_LS && case_proof(cmd1).compare("END") == 0)
	{
		std::cout << "CAP CYCLE TERMINATED!!" << std::endl;
		cap_step = CAP_CYCLE_TERMINATED;
		sender->get_socket().cap.set(cap_step);
	}
	return (0);
}

int	Server::nick(Client *sender, const std::vector<std::string> &cmd)
{
	std::vector<std::string> args;
	std::string cmd1;

	if (cmd.size() <= 1)
		args.push_back(cmd[0]);	
	else if (cmd.size() > 1)
	{
		cmd1 = cmd[1];
		r_trim(cmd1);
		args.push_back(cmd1);	
	}
	if (cmd.size() <= 1)
	{
		Message reply(":"+_hostname, "", ERR_NONICKNAMEGIVEN, get_msg(ERR_NONICKNAMEGIVEN, &args));
		std::string final_msg = reply.aggreg();
		sender->get_socket().send(final_msg);
		return (-1);
	}
	else
	{
		if (sender->get_socket().cap.get() >= WAITING_FOR_CAP_LS)
		{
			std::cout << "ACCEPTED IN CAP SECTION" << std::endl;
			// First we check if the user is already registered 
			// => if he is, then it means he wants to swap nickname
			if (sender->get_user().is_nick_valid(cmd1) == false)
			{
				Message reply(":"+_hostname, "", ERR_ERRONEUSNICKNAME, get_msg(ERR_ERRONEUSNICKNAME, &args));
				std::string final_msg = reply.aggreg();
				sender->get_socket().send(final_msg);
				return (-1);
			}
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
				// std::cout << "TEST\n";
			}
			return 0;
		}
	}
	return (-1);
}

int	Server::user(Client *sender, const std::vector<std::string> &cmd)
{
	// std::cout << "Je suis dans la commande user - " << sender->get_user().nickname.get() << std::endl;
	if (sender->get_socket().cap.get() >= WAITING_FOR_CAP_LS && sender->get_user().nickname.get() != "anonymous")
	{
		// std::cout << "cmd.size(): " << cmd.size() << std::endl;
		if (cmd.size() > 4)
		{	
			std::string u(cmd[1]);
			std::string tmp = "";
			User *cur_user = &sender->get_user();
			cur_user->username.set(u);
			// std::cout << "cmd[1]: " << cmd[1] << std::endl;
			// std::cout << "USERNAME SET:" << cur_user->username.get() << std::endl;
			for (size_t i = 5; i < cmd.size(); i++)
				tmp += cmd[i];
			cur_user->realname.set(tmp);
			// std::cout << "REALNAME SET:" << cur_user->realname.get() << std::endl;
			if (_user_list.find(cmd[1]) == _user_list.end())
				_user_list[cmd[1]] = &sender->get_user(); // we update the user_list with the new nickname / user
			std::vector<std::string> args(1, sender->get_user().fci());
			Message reply(":"+_hostname, cmd[1], RPL_WELCOME, get_msg(RPL_WELCOME, &args)); // WELCOME_MSG + sender->get_user().fci()
			std::string final_msg = reply.aggreg();
			std::cout << "Reply sent before: " << final_msg << std::endl;
			sender->get_socket().send(final_msg);
		}
		return 0;
	}
	return (-1);
}

std::string Server::get_msg(std::string msg_code, std::vector<std::string> *args)
{
	std::string msg_template;
	msg_template = _msg_list[msg_code];
	return(replace_tags(msg_template, args));
}

std::string Server::replace_tags(std::string msg_template, std::vector<std::string> *args)
{
	// find_replace_all(msg_template, "<fci>", "abesombes!abesombes@127.0.0.1");
	int position_tag = 0;
	size_t pos_opentag;
	size_t pos_closetag;
	size_t tag_len;
	for (std::vector<std::string>::iterator it = args->begin(); it < args->end(); it++)
	{
		pos_opentag = msg_template.find("<", position_tag);
		// std::cout << "pos_opentag: " << pos_opentag << std::endl;
		if (pos_opentag != std::string::npos)
		{
			pos_closetag = msg_template.find(">", pos_opentag + 1);
			// std::cout << "pos_closetag: " << pos_closetag << std::endl;
			if (pos_closetag != std::string::npos)
			{
				tag_len = pos_closetag - pos_opentag + 1;
				// std::cout << "tag_len: " << tag_len << std::endl;
				msg_template = msg_template.replace(pos_opentag, tag_len, *it);
				position_tag = pos_opentag + (*it).length();
				// std::cout << "position_tag: " << position_tag << std::endl;
			}
		}
	}
	return (msg_template);
}

// void Server::find_replace_tags(std::string & data, std::string toSearch, std::string replaceStr)
// {
//     // Get the first occurrence
//     size_t pos = data.find(toSearch);
//     // Repeat till end is reached
//     while( pos != std::string::npos)
//     {
//         // Replace this occurrence of Sub String
//         data.replace(pos, toSearch.size(), replaceStr);
//         // Get the next occurrence from the current position
//         pos =data.find(toSearch, pos + replaceStr.size());
//     }
//}