/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:45 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/12 19:49:33 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

String	Message::_set_msg_base	(String code) const
{
	String	msg	= ":"
				+ this->_hostname
				+ " "
				+ code
				+ " ";
	return (msg);
}

String	Message::_set_msg_base	(String code
								,String receiver) const
{
	String	msg	= ":";
	if (receiver == (*this->_users_it)->get_nickname())
		msg	+= this->_hostname;
	else
		msg	+= this->_set_sender();
	msg	+= " "
		+ code
		+ " "
		+ receiver;
	return (msg);
}

String	Message::_set_msg_base	(String sender
								,String code
								,String target) const
{
	String	msg	= ":"
				+ sender
				+ " "
				+ code
				+ " "
				+ target;
	return (msg);
}

String	Message::_set_msg_base	(String sender
								,String code
								,String target
								,time_t time) const
{
	String	msg	= ":"
				+ sender
				+ " "
				+ code
				+ " "
				+ target
				+ " "
				+ ctime(&time);
	return (msg);
}

String	Message::_set_msg_base	(String sender
								,String code
								,String target
								,String txt) const
{
	String	msg	= ":"
				+ sender
				+ " "
				+ code
				+ " "
				+ target
				+ " "
				+ txt;
	return (msg);
}

String	Message::_set_reply_base	(String code) const
{
	String	msg	= this->_set_msg_base(code);

	String	nickname = (*this->_users_it)->get_nickname();
	msg += (nickname == DFL_NICKNAME) ? "* " : nickname + " ";
	return (msg);
}

String	Message::_set_reply_base	(String code
									,String receiver) const
{
	String	msg	= this->_set_msg_base(code)
				+ receiver
				+ " ";
	return (msg);
}

String	Message::_set_sender	(void) const
{
	String	sender	= (*this->_users_it)->get_nickname()
					+ "!"
					+ (*this->_users_it)->get_username()
					+ "@"
					+ this->_servername;
	return (sender);
}

String	Message::_set_sender	(String oldest) const
{
	String	sender	= ":"
					+ oldest
					+ "!"
					+ (*this->_users_it)->get_username()
					+ "@"
					+ this->_servername;
	return (sender);
}

void Message::_broadcast_to_chan_members(String msg) const
{
	User* cur_user = (*this->_users_it);
	String nickname = cur_user->get_nickname();
	std::map<String, String> mailing_list;
    mailing_list[nickname] = nickname;
	User::CHAN_USERMODE chan_usermode = (*this->_users_it)->get_chan_usermode();

	for (User::CHAN_USERMODE::iterator it = chan_usermode.begin(), ite = chan_usermode.end(); it != ite; it++)
	{
		Channel *current_chan = (*(_chans.find((*it).first))).second;
		for (Channel::CHAN_USER_LIST::iterator itu = current_chan->get_chan_user_list().begin(), itue = current_chan->get_chan_user_list().end(); itu != itue; itu++)
		{

			String cur_target = itu->first;
			if (cur_target != nickname && mailing_list.find(cur_target) == mailing_list.end())
			{
				itu->second->add_to_queue(msg);
				mailing_list[cur_target] = cur_target;
			}
		}
	}
}

//void	Message::_init_msg_list	(void)
//{
//	if (Message::_msg_list.size() == 0)
//	{
//		//RETURN MSG
//		Message::_msg_list[ERR_PASSWDMISMATCH] = ":Password incorrect";
//		Message::_msg_list[ERR_NONICKNAMEGIVEN] = ":No nickname given";
//		Message::_msg_list[ERR_NICKNAMEINUSE] = "<nick> :Nickname is already in use";
//		Message::_msg_list[ERR_UNAVAILRESOURCE] = "<nick/channel> :Nick/channel is temporarily unavailable";
//		Message::_msg_list[ERR_RESTRICTED] = ":Your connection is restricted!";
//		Message::_msg_list[ERR_ERRONEUSNICKNAME] = "<nick> :Erroneous nickname";
//		Message::_msg_list[ERR_NEEDMOREPARAMS] = "<command> :Not enough parameters";
//		Message::_msg_list[ERR_ALREADYREGISTRED] = ":Unauthorized command (already registered)";
//		Message::_msg_list[ERR_NOORIGIN] = ":No origin specified";
//		Message::_msg_list[ERR_NOSUCHSERVER] = "<server name> :No such server";
//		Message::_msg_list[RPL_WELCOME] = "Welcome to the Internet Relay Network <fullclientidentifier>";
//		
//		//CMD MSG
//		Message::_msg_list[PONG] = "<server> <server2>";
//		Message::_msg_list[ERROR] = ":<result> Link: <nick> by <serv> (<cause>)";
//	}
//}
//
//		Message::_msg_list[RPL_YOURHOST] = "Your host is <servername>, running version <ver>";
//		Message::_msg_list[RPL_CREATED] = "This server was created <date>";
//		Message::_msg_list[RPL_MYINFO] = "<servername> <version> <available user modes> <available channel modes>";
//		Message::_msg_list[RPL_BOUNCE] = "Try server <server name>, port <port number>";
//		Message::_msg_list[RPL_TRACELINK] = "Link <version & debug level> <destination> <next server> V<protocol version> <link uptime in seconds> <backstream sendq> <upstream sendq>";
//		Message::_msg_list[RPL_TRACECONNECTING] = "Try. <class> <server>";
//		Message::_msg_list[RPL_TRACEHANDSHAKE] = "H.S. <class> <server>";
//		Message::_msg_list[RPL_TRACEUNKNOWN] = "???? <class> [<client IP address in dot form>]";
//		Message::_msg_list[RPL_TRACEOPERATOR] = "Oper <class> <nick>";
//		Message::_msg_list[RPL_TRACEUSER] = "User <class> <nick>";
//		Message::_msg_list[RPL_TRACESERVER] = "Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> V<protocol version>";
//		Message::_msg_list[RPL_TRACESERVICE] = "Service <class> <name> <type> <active type>";
//		Message::_msg_list[RPL_TRACENEWTYPE] = "<newtype> 0 <client name>";
//		Message::_msg_list[RPL_TRACECLASS] = "Class <class> <count>";
//	210?? RPL_TRACERECONNECT
//		Message::_msg_list[RPL_STATSLINKINFO] = "<linkname> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>";
//		Message::_msg_list[RPL_STATSCOMMANDS] = "<command> <count> <byte count> <remote count>";
//		Message::_msg_list[RPL_ENDOFSTATS] = "<stats letter> :End of STATS report";
//		Message::_msg_list[RPL_UMODEIS] = "<user mode string>";
//		Message::_msg_list[RPL_SERVLIST] = "<name> <server> <mask> <type> <hopcount> <info>";
//		Message::_msg_list[RPL_SERVLISTEND] = "<mask> <type> :End of service listing";
//		Message::_msg_list[RPL_STATSUPTIME] = ":Server Up %d days %d:%02d:%02d";
//		Message::_msg_list[RPL_STATSOLINE] = "O <hostmask> * <name>";
//		Message::_msg_list[RPL_LUSERCLIENT] = ":There are <integer> users and <integer> services on <integer> servers";
//		Message::_msg_list[RPL_LUSEROP] = "<integer> :operator(s) online";
//		Message::_msg_list[RPL_LUSERUNKNOWN] = "<integer> :unknown connection(s)";
//		Message::_msg_list[RPL_LUSERCHANNELS] = "<integer> :channels formed";
//		Message::_msg_list[RPL_LUSERME] = ":I have <integer> clients and <integer> servers";
//		Message::_msg_list[RPL_ADMINME] = "<server> :Administrative info"
//		Message::_msg_list[RPL_ADMINLOC1] = ":<admin info>";
//		Message::_msg_list[RPL_ADMINLOC2] = ":<admin info>";
//		Message::_msg_list[RPL_ADMINEMAIL] = ":<admin info>";
//		Message::_msg_list[RPL_TRACELOG] = "File <logfile> <debug level>";
//		Message::_msg_list[RPL_TRACEEND] = "<server name> <version & debug level> :End of TRACE";
//		Message::_msg_list[RPL_TRYAGAIN] = "<command> :Please wait a while and try again.";
//		Message::_msg_list[RPL_AWAY] = "<nick> :<away message>";
//		Message::_msg_list[RPL_USERHOST] = ":*1<reply> *( " " <reply> )";
//		Message::_msg_list[RPL_ISON] = ":*1<nick> *( " " <nick> )";
//		Message::_msg_list[RPL_UNAWAY] = ":You are no longer marked as being away";
//		Message::_msg_list[RPL_NOWAWAY] = ":You have been marked as being away";
//		Message::_msg_list[RPL_WHOISUSER] = "<nick> <user> <host> * :<real name>";
//		Message::_msg_list[RPL_WHOISSERVER] = "<nick> <server> :<server info>";
//		Message::_msg_list[RPL_WHOISOPERATOR] = "<nick> :is an IRC operator";
//		Message::_msg_list[RPL_WHOWASUSER] = "<nick> <user> <host> * :<real name>";
//		Message::_msg_list[RPL_ENDOFWHO] = "<name> :End of WHO list";
//		Message::_msg_list[RPL_WHOISIDLE] = "<nick> <integer> :seconds idle";
//		Message::_msg_list[RPL_ENDOFWHOIS] = "<nick> :End of WHOIS list";
//		Message::_msg_list[RPL_WHOISCHANNELS] = "<nick> :*( ( '@' / '+' ) <channel> " " )";
//	321 ? RPL_LISTART
//		Message::_msg_list[RPL_LIST] = "<channel> <# visible> :<topic>";
//		Message::_msg_list[RPL_LISTEND] = ":End of LIST";
//		Message::_msg_list[RPL_CHANNELMODEIS] = "<channel> <mode> <mode params>";
//		Message::_msg_list[RPL_UNIQOPIS] = "<channel> <nickname>";
//		Message::_msg_list[RPL_NOTOPIC] = "<channel> :No topic is set";
//		Message::_msg_list[RPL_TOPIC] = "<channel> :<topic>";
//		Message::_msg_list[RPL_INVITING] = "<channel> <nick>";
//		Message::_msg_list[RPL_SUMMONING] = "<user> :Summoning user to IRC";
//		Message::_msg_list[RPL_INVITELIST] = "<channel> <invitemask>";
//		Message::_msg_list[RPL_ENDOFINVITELIST] = "<channel> :End of channel invite list";
//		Message::_msg_list[RPL_EXCEPTLIST] = "<channel> <exceptionmask>";
//		Message::_msg_list[RPL_ENDOFEXCEPTLIST] = "<channel> :End of channel exception list";
//		Message::_msg_list[RPL_VERSION] = "<version>.<debuglevel> <server> :<comments>";
//		Message::_msg_list[RPL_WHOREPLY] = "<channel> <user> <host> <server> <nick> ( 'H' / 'G' > ['*'] [ ( '@' / '+' ) ] :<hopcount> <real name>";
//		Message::_msg_list[RPL_NAMREPLY] = "( '=' / '*' / '@' ) <channel> :[ '@' / '+' ] <nick> *( " " [ '@' / '+' ] <nick> )";
//		Message::_msg_list[RPL_LINKS] = "<mask> <server> :<hopcount> <server info>";
//		Message::_msg_list[RPL_ENDOFLINKS] = "<mask> :End of LINKS list";
//		Message::_msg_list[RPL_ENDOFNAMES] = "<channel> :End of NAMES list";
//		Message::_msg_list[RPL_BANLIST] = "<channel> <banmask>";
//		Message::_msg_list[RPL_ENDOFBANLIST] = "<channel> :End of channel ban list";
//		Message::_msg_list[RPL_ENDOFWHOWAS] = "<nick> :End of WHOWAS";
//		Message::_msg_list[RPL_INFO] = ":<string>";
//		Message::_msg_list[RPL_MOTD] = ":- <text>";
//		Message::_msg_list[RPL_ENDOFINFO] = ":End of INFO list";
//		Message::_msg_list[RPL_MOTDSTART] = ":- <server> Message of the day - ";
//		Message::_msg_list[RPL_ENDOFMOTD] = ":End of MOTD command";
//		Message::_msg_list[RPL_YOUREOPER] = ":You are now an IRC operator";
//		Message::_msg_list[RPL_REHASHING] = "<config file> :Rehashing";
//		Message::_msg_list[RPL_YOURESERVICE] = "You are service <servicename>";
//		Message::_msg_list[RPL_TIME] = "<server> :<string showing server's local time>";
//		Message::_msg_list[RPL_USERSSTART] = ":UserID Terminal Host";
//		Message::_msg_list[RPL_USERS] = ":<username> <ttyline> <hostname>";
//		Message::_msg_list[RPL_ENDOFUSERS] = ":End of users";
//		Message::_msg_list[RPL_NOUSERS] = ":Nobody logged in";
//		Message::_msg_list[ERR_NOSUCHNICK] = "<nickname> :No such nick/channel";
//		Message::_msg_list[ERR_NOSUCHCHANNEL] = "<channel name> :No such channel";
//		Message::_msg_list[ERR_CANNOTSENDTOCHAN] = "<channel name> :Cannot send to channel";
//		Message::_msg_list[ERR_TOOMANYCHANNELS] = "<channel name> :You have joined too many channels";
//		Message::_msg_list[ERR_WASNOSUCHNICK] = "<nickname> :There was no such nickname";
//		Message::_msg_list[ERR_TOOMANYTARGETS] = "<target> :<error code> recipients. <abort message>";
//		Message::_msg_list[ERR_NOSUCHSERVICE] = "<service name> :No such service";
//		Message::_msg_list[ERR_NORECIPIENT] = ":No recipient given (<command>)";
//		Message::_msg_list[ERR_NOTEXTTOSEND] = ":No text to send";
//		Message::_msg_list[ERR_NOTOPLEVEL] = "<mask> :No toplevel domain specified";
//		Message::_msg_list[ERR_WILDTOPLEVEL] = "<mask> :Wildcard in toplevel domain";
//		Message::_msg_list[ERR_BADMASK] = "<mask> :Bad Server/host mask";
//		Message::_msg_list[ERR_UNKNOWNCOMMAND] = "<command> :Unknown command";
//		Message::_msg_list[ERR_NOMOTD] = ":MOTD File is missing";
//		Message::_msg_list[ERR_NOADMININFO] = "<server> :No administrative info available";
//		Message::_msg_list[ERR_FILEERROR] = ":File error doing <file op> on <file>";
//		Message::_msg_list[ERR_NICKCOLLISION] = "<nick> :Nickname collision KILL from <user>@<host>";
//		Message::_msg_list[ERR_USERNOTINCHANNEL] = "<nick> <channel> :They aren't on that channel";
//		Message::_msg_list[ERR_NOTONCHANNEL] = "<channel> :You're not on that channel";
//		Message::_msg_list[ERR_USERONCHANNEL] = "<user> <channel> :is already on channel";
//		Message::_msg_list[ERR_NOLOGIN] = "<user> :User not logged in";
//		Message::_msg_list[ERR_SUMMONDISABLED] = ":SUMMON has been disabled";
//		Message::_msg_list[ERR_USERSDISABLED] = ":USERS has been disabled";
//		Message::_msg_list[ERR_NOTREGISTERED] = ":You have not registered";
//		Message::_msg_list[ERR_NOPERMFORHOST] = ":Your host isn't among the privileged";
//		Message::_msg_list[ERR_YOUREBANNEDCREEP] = ":You are banned from this server";
//		Message::_msg_list[ERR_KEYSET] = "<channel> :Channel key already set";
//		Message::_msg_list[ERR_CHANNELISFULL] = "<channel> :Cannot join channel (+l)";
//		Message::_msg_list[ERR_UNKNOWNMODE] = "<char> :is unknown mode char to me for <channel>";
//		Message::_msg_list[ERR_INVITEONLYCHAN] = "<channel> :Cannot join channel (+i)";
//		Message::_msg_list[ERR_BANNEDFROMCHAN] = "<channel> :Cannot join channel (+b)";
//		Message::_msg_list[ERR_BADCHANNELKEY] = "<channel> :Cannot join channel (+k)";
//		Message::_msg_list[ERR_BADCHANMASK] = "<channel> :Bad Channel Mask";
//		Message::_msg_list[ERR_NOCHANMODES] = "<channel> :Channel doesn't support modes";
//		Message::_msg_list[ERR_BANLISTFULL] = "<channel> <char> :Channel list is full";
//		Message::_msg_list[ERR_NOPRIVILEGES] = ":Permission Denied- You're not an IRC operator";
//		Message::_msg_list[ERR_CHANOPRIVSNEEDED] = "<channel> :You're not channel operator";
//		Message::_msg_list[ERR_CANTKILLSERVER] = ":You can't kill a server!";
//		Message::_msg_list[ERR_UNIQOPPRIVSNEEDED] = ":You're not the original channel operator";
//		Message::_msg_list[ERR_NOOPERHOST] = ":No O-lines for your host";
//		Message::_msg_list[ERR_UMODEUNKNOWNFLAG] = ":Unknown MODE flag";
//		Message::_msg_list[ERR_USERSDONTMATCH] = ":Cannot change mode for other users";

