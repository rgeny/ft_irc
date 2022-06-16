/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:19:17 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/16 22:06:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel	(void)
{
	std::cout	<< "Channel dfl constructor."
				<< std::endl;
}

Channel::Channel(String &name
				,String password)
	:_name(name)
	,_password(password)
{
	// this->_creation = time(0);
	time(&this->_creation);
	std::cout	<< "Channel Param constructor."
				<< std::endl;
	this->_mode.resize(14);
	for (int i = 0; i < 14; i++)
		this->_mode[i] = false;
	_limit = 0;
}

Channel::Channel	(Channel const & src)
{
	(void)src;
	std::cout	<< "Channel cpy constructor."
				<< std::endl;
}

Channel::~Channel	(void)
{
	std::cout	<< "Channel destructor."
				<< std::endl;
}

