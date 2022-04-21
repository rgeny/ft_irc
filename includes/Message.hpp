/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/21 22:52:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include <string>
# include <map>
# include "User.hpp"
# include "defines.hpp"

#include "Accessor.hpp"

class Message
{
	public:
		Accessor<std::string>	msg_code;
		Accessor<std::string>	msg_content;

		// tmp
		Message();
		// fin tmp

		Message		(std::string sender
					,std::string receiver
					,std::string msg_code
					,std::string msg_content);
		Message		(Message const & src);
		~Message	(void);

		Message & operator=(Message const & rhs);

		std::string	getSender	(void) const;
		std::string	getReceiver	(void) const;
		void		setSender	(std::string & sender);
		void		setReceiver	(std::string & receiver);
		std::string	get_msg		(std::string & msg_code
								,std::vector<std::string> & args
								,std::map<std::string, std::string> & _msg_list);

		void				add_arg			(std::string arg);
		size_t				size_arg		(void);
		const std::string &	forge			(std::string sender
											,std::string msg_code);
		std::string			replace_tags	(std::string msg_template
											,std::vector<std::string> &	args);
		std::string const &	aggreg			(void);

	private:

		static std::map<std::string, std::string>	_msg_list;

		std::string 				_sender;
		std::string 				_receiver;
		std::vector<std::string>	_msg_args;
};

std::ostream &	operator<<	(std::ostream & o
							,Message const & instance);

#endif
