/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:36:54 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/22 18:43:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel	(void)
{
	std::cout	<< "Channel dfl constructor."
				<< std::endl;
}

Channel::Channel(std::string 	const & name
				,std::string 	const & topic
				,std::vector<bool> 	const & mode
				,std::string 	const & password
				,std::size_t 	const & limit
				,bool			const & is_safe
				,int			const &	reop_delay
				)
	:
	_name(name),
	_topic(topic),
	_mode(mode),
	_password(password),
	_limit(limit),
	_creation(time(0)),
	_is_safe(is_safe),
	_reop_delay(reop_delay)
{
	// std::cout << "Parameterized constructor Channel" << std::endl;
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

