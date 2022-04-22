/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:51:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/22 14:37:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

std::map<std::string, std::string>	Message::_msg_list;

Message:: Message	(void)
	:_sender()
	,_receiver()
	,msg_code("")
	,msg_content("")
{
	std::cout	<< "Message dfl constructor."
				<< std::endl;
	this->_init_msg_list();
}

Message:: Message	(std::string sender
					,std::string receiver
					,std::string txt
					,std::string commandCalled)
	:msg_code(txt)
	,msg_content(commandCalled)
{
	this->_init_msg_list();
	if (!sender.empty())
		_sender = sender;
	else
		_sender = "";
	if (!receiver.empty())
		_receiver = receiver;
	else
		_receiver  = "*";
	std::cout	<< "Parameterized constructor Message."
				<< std::endl;
}

Message:: Message	(Message const & src)
{
	this->_init_msg_list();
	(void)src;
	std::cout	<< "Message cpy constructor."
				<< std::endl;
}

Message::~Message	(void)
{
	std::cout	<< "Message destructor."
				<< std::endl;
}
