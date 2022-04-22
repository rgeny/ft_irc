/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/22 16:08:26 by abesombe         ###   ########.fr       */
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

		std::string	get_msg		(std::string & msg_code
								,std::vector<std::string> & args);

//		void				main			(std::string msg_code
//											,Client * client);

		void				add_arg			(std::string arg);
		size_t				size_arg		(void);
		const std::string	forge			(std::string sender
											,std::string msg_code);
		std::string			replace_tags	(std::string msg_template
											,std::vector<std::string> &	args);
		std::string const	aggreg			(void);
		void				set_receiver	(std::string receiver);

	private:

		static std::map<std::string, std::string>	_msg_list;

		Client *					_client;
//		std::string					_msg_code;

		void	_init_msg_list	(void);

		std::string					_msg_content;
		std::string 				_sender;
		std::string 				_receiver;
		std::vector<std::string>	_msg_args;
};

std::ostream &	operator<<	(std::ostream & o
							,Message const & instance);

#endif
