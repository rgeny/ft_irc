/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/18 19:07:54 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

Message & Message::operator=(Message const & rhs)
{
	this->_sender = rhs.getSender();
	this->_receiver = rhs.getReceiver();
	this->msg_code = rhs.msg_code.get();
	this->msg_content = rhs.msg_content.get();
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
		<< instance.msg_code.get()
		<< "\nCMD: "
		<< instance.msg_content.get();
	return (o);
}