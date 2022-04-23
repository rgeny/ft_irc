/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/23 04:11:51 by rgeny            ###   ########.fr       */
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
		Message		(std::string * servername);
		Message		(Message const & src);
		~Message	(void);

		Message & operator=(Message const & rhs);

		void	set_sender		(std::string sender);
		void	set_receiver	(std::string receiver);

		void				add_arg			(std::string arg);
		std::string const	forge			(std::string msg_code);

	private:
		static std::map<std::string, std::string>	_msg_list;

		Message	(void);

		const std::string *			_servername;
		std::string					_sender;
		std::string 				_receiver;
		std::vector<std::string>	_msg_args;


		std::string		_get_msg		(std::string & msg_code
										,std::vector<std::string> & args);
		std::string		_replace_tags	(std::string msg_template
										,std::vector<std::string> &	args);
		void			_clear_data		(void);
		void			_init_msg_list	(void);
};

std::ostream &	operator<<	(std::ostream & o
							,Message const & instance);

#endif
