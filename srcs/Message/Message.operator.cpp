/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/25 21:19:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

Message & Message::operator=(Message const & rhs)
{
	(void)rhs;
//	this->_sender = rhs._sender;
//	this->_receiver = rhs._receiver;
//	this->msg_code = rhs.msg_code.get();
//	this->msg_content = rhs.msg_content.get();
	return (*this);
}
//
//std::ostream&	operator<<( std::ostream& o, Message const & instance)
//{
//	
//	o	<< "MESSAGE\n"
//		<< "FROM: "
//		<< instance.getSender()
//		<< "\nTO: "
//		<< instance.getReceiver()
//		<< "\nTXT: "
//		<< instance.msg_code.get()
//		<< "\nCMD: "
//		<< instance.msg_content.get();
//	return (o);
//}
