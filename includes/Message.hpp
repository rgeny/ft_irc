/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:18:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 16:24:17 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <iostream>
#include <string>
#include "User.hpp"

#include "Accessor.hpp"

class Message
{
	private:
		Message();
		User					*_sender;
		User					*_receiver;
	public:
		Accessor<std::string>	txt;
		Accessor<std::string>	commandCalled;

		Message(User * sender,
				User * receiver,
				std::string const & txt,
				std::string const & commandCalled);
		Message( Message const & src);
		Message & operator=(Message const & rhs);
		~Message();

		User *				getSender() const;
		User *				getReceiver() const;
		void				setSender(User * sender);
		void				setReceiver(User * receiver);
		
};

std::ostream&	operator<<( std::ostream& o, Message const & instance);

#endif