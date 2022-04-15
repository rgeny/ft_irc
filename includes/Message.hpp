/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/15 18:02:32 by abesombe         ###   ########.fr       */
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
		Accessor<std::string>	txt;
		Accessor<std::string>	commandCalled;

		Message(std::string sender,
				std::string receiver,
				std::string txt,
				std::string commandCalled);
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