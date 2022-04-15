/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:20 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/15 17:41:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

Message::Message()
	:
	_sender(NULL),
	_receiver(NULL),
	txt(""),
	commandCalled("")
{
	// std::cout << "Default constructor Message" << std::endl;
}

Message::Message(std::string sender
				,std::string receiver
				,std::string txt
				,std::string commandCalled)
	:
	_sender(sender),
	_receiver(receiver),
	txt(txt),
	commandCalled(commandCalled)
{
	// std::cout << "Parameterized constructor Message" << std::endl;
}

Message::Message( Message const & src)
	:
	_sender(src.getSender()),
	_receiver(src.getReceiver()),
	txt(src.txt.get()),
	commandCalled(src.commandCalled.get())
{
	// std::cout << "Copy constructor Message" << std::endl;
}

Message::~Message()
{
	// std::cout << "Destructor Message" << std::endl;
}