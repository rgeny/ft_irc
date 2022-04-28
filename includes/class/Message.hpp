/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/28 11:07:32 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include <map>
# include "defines.hpp"
# include "Data.hpp"
# include "String.hpp"

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

//		void	set_sender		(String sender);
//		void	set_receiver	(String receiver);

//		void				add_arg			(String arg);
//		String const	forge			(String msg_code);

	protected:
		//error reply
		e_error	_err_passwdmismatch		(void) const;
		e_error	_err_nonicknamegiven	(void) const;
		e_error	_err_nicknameinuse		(void) const;
		e_error	_err_unavailresource	(void) const;
		e_error	_err_restricted			(void) const;
		e_error	_err_erroneusnickname	(void) const;
		e_error	_err_needmoreparams		(void) const;
		e_error	_err_alreadyregistred	(void) const;
		e_error	_err_noorigin			(void) const;
		e_error	_err_nosuchserver		(void) const;

		//reply
		e_error	_rpl_welcome			(void) const;

		//command reply
		e_error	_cmd_pong				(void) const;
		e_error	_cmd_join				(void) const;
		e_error	_cmd_error				(e_error code);
	

	private:
		MsgError	_msg_error;

		void	_init_msg_error	(void);

		String	_set_msg_base	(String code) const;
		String	_set_msg_base	(String sender, String code, String target) const;

		String	_set_reply_base	(String code) const;
		String	_set_reply_base	(String code
									,String receiver) const;
//		String	set_msg_base	(String receiver) const;




//		static std::map<String, String>	_msg_list;
//
//		String					_sender;
//		String 				_receiver;
//		std::vector<String>	_msg_args;
//
//
//		String		_get_msg		(String & msg_code
//										,std::vector<String> & args);
//		String		_replace_tags	(String msg_template
//										,std::vector<String> &	args);
//		void			_clear_data		(void);
//		void			_init_msg_list	(void);
};
//
//std::ostream &	operator<<	(std::ostream & o
//							,Message const & instance);

#endif
