/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:19:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/27 21:13:41 by rgeny            ###   ########.fr       */
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

