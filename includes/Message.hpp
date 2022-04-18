/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/18 19:05:38 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

# include <iostream>
# include <string>
# include <map>
# include "User.hpp"

#include "Accessor.hpp"

class Message
{
	private:
		Message();
		std::string					_sender;
		std::string					_receiver;
	public:
		Accessor<std::string>	msg_code;
		Accessor<std::string>	msg_content;

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
		void				setSender(std::string& sender);
		void				setReceiver(std::string& receiver);
		
};

std::ostream&	operator<<( std::ostream& o, Message const & instance);

#endif