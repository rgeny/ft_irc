/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:20 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/18 19:15:38 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

Message::Message()
	:
	_sender(""),
	_receiver(""),
	msg_code(""),
	msg_content("")
{
	// std::cout << "Default constructor Message" << std::endl;
}

Message::Message(std::string sender
				,std::string receiver
				,std::string txt
				,std::string commandCalled)
	:
	msg_code(txt),
	msg_content(commandCalled)
{
	if (!sender.empty())
		_sender = sender;
	else
		_sender = "*";
	if (!receiver.empty())
		_receiver = receiver;
	else
		_receiver = "*";
	// std::cout << "Parameterized constructor Message" << std::endl;
}

Message::Message( Message const & src)
	:
	_sender(src.getSender()),
	_receiver(src.getReceiver()),
	msg_code(src.msg_code.get()),
	msg_content(src.msg_content.get())
{
	// std::cout << "Copy constructor Message" << std::endl;
}

Message::~Message()
{
	// std::cout << "Destructor Message" << std::endl;
}