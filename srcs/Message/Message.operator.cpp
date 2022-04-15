/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/15 17:41:18 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

Message & Message::operator=(Message const & rhs)
{
	this->_sender = rhs.getSender();
	this->_receiver = rhs.getReceiver();
	this->txt = rhs.txt.get();
	this->commandCalled = rhs.commandCalled.get();
	return (*this);
}

std::ostream&	operator<<( std::ostream& o, Message const & instance)
{
	o	<< "MESSAGE\n"
		<< "FROM: "
		<< instance.getSender()
		<< "\nTO: "
		<< instance.getReceiver()
		<< "\nTXT: "
		<< instance.txt.get()
		<< "\nCMD: "
		<< instance.commandCalled.get();
	return (o);
}