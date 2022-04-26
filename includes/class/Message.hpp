/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/26 17:41:52 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include <string>
# include <map>
# include "defines.hpp"
# include "Data.hpp"

# include "e_error.hpp"

class Message
	:virtual protected Data
{
	public:
		typedef std::map<e_error, std::string>	MsgError;
		typedef MsgError::const_iterator		MsgError_it;

		Message		(void);
		Message		(Message const & src);
		~Message	(void);

		Message & operator=(Message const & rhs);

//		void	set_sender		(std::string sender);
//		void	set_receiver	(std::string receiver);

//		void				add_arg			(std::string arg);
//		std::string const	forge			(std::string msg_code);

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
		e_error	_cmd_error				(e_error code) const;
	

	private:
		MsgError	_msg_error;

		void	_init_msg_error	(void);

		std::string	_set_msg_base	(std::string code) const;

		std::string	_set_reply_base	(std::string code) const;
		std::string	_set_reply_base	(std::string code
									,std::string receiver) const;
//		std::string	set_msg_base	(std::string receiver) const;




//		static std::map<std::string, std::string>	_msg_list;
//
//		std::string					_sender;
//		std::string 				_receiver;
//		std::vector<std::string>	_msg_args;
//
//
//		std::string		_get_msg		(std::string & msg_code
//										,std::vector<std::string> & args);
//		std::string		_replace_tags	(std::string msg_template
//										,std::vector<std::string> &	args);
//		void			_clear_data		(void);
//		void			_init_msg_list	(void);
};
//
//std::ostream &	operator<<	(std::ostream & o
//							,Message const & instance);

#endif
