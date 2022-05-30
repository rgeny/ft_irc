/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:51:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

//std::map<std::string, std::string>	Message::_msg_list;

Message:: Message	(void)
{
	std::cout	<< "Message dfl constructor."
				<< std::endl;
	this->_init_msg_error();
}

Message:: Message	(Message const & src)
	:Data()
{
	(void)src;
	std::cout	<< "Message cpy constructor."
				<< std::endl;
	this->_init_msg_error();
}

Message::~Message	(void)
{
	std::cout	<< "Message destructor."
				<< std::endl;
}
