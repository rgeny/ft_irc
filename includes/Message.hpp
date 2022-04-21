/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/21 15:24:31 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include "User.hpp"

#include "Accessor.hpp"

class Message
{
	private:
		
		std::string					_sender;
		std::string					_receiver;
		std::vector<std::string> 	_msg_args;
		
	public:
		Accessor<std::string>		msg_code;
		Accessor<std::string>		msg_content;

		Message();
		Message(std::string sender,
				std::string receiver,
				std::string msg_code,
				std::string msg_content);
		Message( Message const & src);
		std::string const & aggreg(void);
		Message & operator=(Message const & rhs);
		~Message();

		std::string				getSender() const;
		std::string				getReceiver() const;
		void					setSender(std::string& sender);
		void					setReceiver(std::string& receiver);
		void					add_arg(std::string &arg);
		size_t 					size_arg(void);
		std::string 			get_msg(std::string & msg_code, std::vector<std::string> & args, std::map<std::string, std::string> & _msg_list);
		const std::string &		forge(std::string & sender, std::string msg_code, std::map<std::string, std::string> & _msg_list);
		std::string 			replace_tags(std::string msg_template, std::vector<std::string> & args);
};

std::ostream&	operator<<( std::ostream& o, Message const & instance);

#endif