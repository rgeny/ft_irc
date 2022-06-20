/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/20 13:38:37 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include <map>
# include "defines.hpp"
# include "Data.hpp"
# include "String.hpp"
# include "User.hpp"
# include "Channel.hpp"

# include "e_error.hpp"

class Message
	:virtual protected Data
{
	public:
		typedef std::map<e_error, String>	MsgError;
		typedef MsgError::const_iterator		MsgError_it;

		Message		(void);
		Message		(Message const & src);
		~Message	(void);

		Message & operator=(Message const & rhs);

	protected:
		//error reply
		e_error	_err_alreadyregistred	(void) const;
		e_error _err_alreadyinbanlist	(String chan_name, String target) const;
		e_error	_err_badchanmask		(void) const;
		e_error	_err_badchannelkey		(void) const;
		e_error	_err_banlistfull		(void) const;
		e_error	_err_bannedfromchan		(void) const;
		e_error	_err_cannotsendtochan	(String reason) const;
		e_error	_err_channelisfull		(void) const;
		e_error	_err_chanoprivsneeded	(String reason = "You must be a channel operator") const;
		e_error	_err_erroneusnickname	(void) const;
		e_error	_err_inviteonlychan		(void) const;	
		e_error	_err_keyset				(void) const;				
		e_error	_err_needmoreparams		(String erroneous_elem, String reason = ": Not enough parameters.") const;
		e_error	_err_nicknameinuse		(void) const;
		e_error	_err_nonicknamegiven	(void) const;
		e_error	_err_noorigin			(void) const;
		e_error	_err_nosuchchannel		(String chan_name) const;
		e_error	_err_nosuchnick			(String nickname) const;
		e_error	_err_nosuchserver		(void) const;
		e_error	_err_notonchannel		(void) const;
		e_error _err_notinbanlist		(String chan_name, String target) const;
		e_error	_err_passwdmismatch		(void) const;
		e_error	_err_restricted			(void) const;
		e_error	_err_umodeunknownflag	(String failed, String reason) const;
		e_error	_err_unavailresource	(void) const;
		e_error	_err_usersdontmatch		(void) const;
		e_error	_err_usernotinchannel	(String nickname, String chan_name) const;
		e_error	_err_useronchannel		(void) const;
		e_error	_err_noprivileges		(String reason) const;
		e_error	_err_toomanymatches		(void) const;
		e_error	_err_unknowncommand		(void) const;
		e_error	_err_nooperhost			(void) const;

		//reply
		e_error	_rpl_banlist			(void) const;		
		e_error	_rpl_channelmodeis		(void) const;
		e_error	_rpl_created			(void) const;
		e_error	_rpl_creationtime		(void) const;
		e_error	_rpl_endofbanlist		(void) const;	
		e_error	_rpl_endofnames			(bool empty) const;	
		e_error	_rpl_endofwho			(String target) const;
		e_error	_rpl_endofwhois			(void) const;
		e_error	_rpl_inviting			(void) const;
		e_error	_rpl_list				(std::vector<String> list) const;
		e_error	_rpl_listend			(void) const;
		e_error	_rpl_liststart			(void) const;
		e_error	_rpl_luserclient		(void) const;
		e_error	_rpl_luserchannels		(void) const;
		e_error	_rpl_luserme			(void) const;
		e_error	_rpl_luserop			(void) const;
		e_error	_rpl_myinfo				(void) const;
		e_error	_rpl_namreply			(String name_list) const;
		e_error	_rpl_notopic			(void) const;
		e_error	_rpl_topic				(void) const;
		e_error	_rpl_topicwhotime		(void) const;
		e_error	_rpl_umodeis			(String user_mode) const;
		e_error	_rpl_welcome			(void) const;
		e_error	_rpl_whoisuser			(String user_details) const;
		e_error	_rpl_whoischannels		(String user_chan_list) const;
		e_error	_rpl_whoisserver		(void) const;		
		e_error	_rpl_whoreply			(String who_list, String chan_name) const;
		e_error	_rpl_youreoper			(void) const;
		e_error	_rpl_yourhost			(void) const;

		//command reply
		e_error	_cmd_error		(e_error code);
		e_error	_cmd_invite		(void) const;
		e_error	_cmd_join		(void) const;
		e_error	_cmd_kick		(String reason, String kicked, bool broadcast) const;
		e_error	_cmd_mode		(int broadcast, String mode_change, String args_list) const;
		e_error	_cmd_notice		(String chat_msg) const;
		e_error	_cmd_part		(String reason) const;
		e_error	_cmd_pong		(void) const;
		e_error	_cmd_privmsg	(String chat_msg) const;
		e_error	_cmd_quit		(void) const;
		e_error	_cmd_topic		(int choice) const;
		e_error	_cmd_userhost	(String userhost_list) const;
		e_error	_cmd_info		(void) const;
		e_error	_cmd_motd		(void) const;
		e_error	_cmd_time		(void) const;
		e_error	_cmd_nick		(String & oldest) const;

//	private:
		MsgError	_msg_error;

		void	_init_msg_error	(void);

		String	_set_msg_base	(String code) const;
		String	_set_msg_base	(String code
								,String receiver) const;
		String	_set_msg_base	(String sender
								,String code
								,String target) const;

		String	_set_msg_base	(String sender
								,String code
								,String target
								,time_t time) const;
								
		String	_set_msg_base	(String sender
								,String code
								,String target
								,String txt) const;
								
		String	_set_reply_base	(String code) const;
		String	_set_reply_base	(String code
								,String receiver) const;

		String	_set_sender		(void) const;
		String	_set_sender		(String oldest) const;
		void	_broadcast_to_chan_members(String msg) const;
};

#endif
