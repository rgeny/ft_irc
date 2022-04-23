/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:51:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 03:55:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

std::map<std::string, std::string>	Message::_msg_list;

Message:: Message	(void)
	:_servername(NULL)
{
	std::cout	<< "Message dfl constructor."
				<< std::endl;
	this->_init_msg_list();
}

Message:: Message	(std::string * servername)
	:_servername(servername)
{
	std::cout	<< "Message parameter constructor."
				<< std::endl;
	this->_init_msg_list();
}

Message:: Message	(Message const & src)
	:_servername(src._servername)
{
	(void)src;
	std::cout	<< "Message cpy constructor."
				<< std::endl;
	this->_init_msg_list();
}

Message::~Message	(void)
{
	std::cout	<< "Message destructor."
				<< std::endl;
}
