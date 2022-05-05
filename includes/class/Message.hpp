/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/05 11:04:28 by abesombe         ###   ########.fr       */
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
		e_error	_err_badchanmask		(void) const;
		e_error	_err_cannotsendtochan	(String reason) const;
		e_error	_err_chanoprivsneeded	(void) const;
		e_error	_err_erroneusnickname	(void) const;
		e_error	_err_needmoreparams		(void) const;
		e_error	_err_nicknameinuse		(void) const;
		e_error	_err_nonicknamegiven	(void) const;
		e_error	_err_noorigin			(void) const;
		e_error	_err_nosuchchannel		(void) const;
		e_error	_err_nosuchnick			(void) const;
		e_error	_err_nosuchserver		(void) const;
		e_error	_err_notonchannel		(void) const;
		e_error	_err_passwdmismatch		(void) const;
		e_error	_err_restricted			(void) const;
		e_error	_err_umodeunknownflag	(String failed, String reason) const;
		e_error	_err_unavailresource	(void) const;
		e_error	_err_usersdontmatch		(void) const;
		e_error	_err_usernotinchannel	(void) const;
		e_error	_err_noprivileges		(String reason) const;

		//reply
		e_error	_rpl_channelmodeis		(void) const;
		e_error	_rpl_creationtime		(void) const;
		e_error	_rpl_welcome			(void) const;

		//command reply
		e_error	_cmd_error				(e_error code);
		e_error	_cmd_join				(void) const;
		e_error	_cmd_kick				(String reason, String kicked) const;
		e_error	_cmd_mode				(int broadcast) const;
		e_error	_cmd_part				(String reason) const;
		e_error	_cmd_pong				(void) const;
		e_error	_cmd_privmsg			(String chat_msg) const;
		e_error	_cmd_topic				(int choice) const;
		e_error	_cmd_userhost			(String userhost_list) const;
		e_error	_cmd_info				(void) const;
		e_error	_cmd_motd				(void) const;
		e_error	_cmd_time				(void) const;

	private:
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
};

#endif
