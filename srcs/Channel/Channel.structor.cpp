/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:19:17 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/15 18:57:39 by abesombes        ###   ########.fr       */
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

// Channel::Channel(String 	const & name
// 				,String 	const & topic
// 				,std::vector<bool> 	const & mode
// 				,String 	const & password
// 				,std::size_t 	const & limit
// 				,bool			const & is_safe
// 				,int			const &	reop_delay
// 				)
// 	:
// 	_name(name),
// 	_topic(topic),
// 	_mode(mode),
// 	_password(password),
// 	_limit(limit),
// 	_creation(time(0)),
// 	_is_safe(is_safe),
// 	_reop_delay(reop_delay)
// {
// 	// std::cout << "Parameterized constructor Channel" << std::endl;
// }

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

