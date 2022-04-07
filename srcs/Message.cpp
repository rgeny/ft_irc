/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:22:33 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 16:26:11 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Message.hpp"

Message::Message()
	:
	_sender(NULL),
	_receiver(NULL),
	txt(""),
	commandCalled("")
{
	// std::cout << "Default constructor Message" << std::endl;
}

Message::Message(User *sender
				,User *receiver
				,std::string const & txt
				,std::string const & commandCalled)
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

Message & Message::operator=(Message const & rhs)
{
	this->_sender = rhs.getSender();
	this->_receiver = rhs.getReceiver();
	this->txt = rhs.txt.get();
	this->commandCalled = rhs.commandCalled.get();
	return (*this);
}

Message::~Message()
{
	// std::cout << "Destructor Message" << std::endl;
}

User *	Message::getSender() const
{
	return (this->_sender);
}

User *	Message::getReceiver() const
{
	return (this->_receiver);
}

void	Message::setSender(User * sender)
{
	this->_sender = sender;
}

void	Message::setReceiver(User * receiver)
{
	this->_receiver = receiver;
}

std::ostream&	operator<<( std::ostream& o, Message const & instance)
{
	o	<< "MESSAGE\n"
		<< "FROM: "
		<< *instance.getSender()
		<< "\nTO: "
		<< *instance.getReceiver()
		<< "\nTXT: "
		<< instance.txt.get()
		<< "\nCMD: "
		<< instance.commandCalled.get();
	return (o);
}