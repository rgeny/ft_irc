/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:19:17 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 16:16:14 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"

Channel::Channel()
	:
	name(""),
	topic(""),
	mode(""),
	password(""),
	limit(0),
	creation(time(0))
{
	// std::cout << "Default constructor Channel" << std::endl;
}

Channel::Channel(std::string const & name
				,std::string const & topic
				,std::string const & mode
				,std::string const & password
				,std::size_t limit)
	:
	name(name),
	topic(topic),
	mode(mode),
	password(password),
	limit(limit),
	creation(time(0))
{
	// std::cout << "Parameterized constructor Channel" << std::endl;
}

Channel::Channel( Channel const & src)
	:
	name(src.name.get()),
	topic(src.topic.get()),
	mode(src.mode.get()),
	password(src.password.get()),
	limit(src.limit.get()),
	creation(src.creation.get())
{
	// std::cout << "Copy constructor Channel" << std::endl;
}

Channel & Channel::operator=(Channel const & rhs)
{
	this->name = rhs.name.get();
	this->topic = rhs.topic.get();
	this->mode = rhs.mode.get();
	this->password = rhs.password.get();
	this->limit = rhs.limit.get();
	this->creation = rhs.creation.get();
	return (*this);
}

Channel::~Channel()
{
	// std::cout << "Destructor Channel" << std::endl;
}

std::ostream&	operator<<( std::ostream& o, Channel const & instance)
{
	time_t	time = instance.creation.get();
	char* dt = ctime(&time);
	
	o	<< "CHANNEL"
		<< " NAME: "
		<< instance.name.get()
		<< " TOPIC: "
		<< instance.topic.get()
		<< " MODE: "
		<< instance.mode.get()
		<< " PASSWORD: "
		<< instance.password.get()
		<< " LIMIT: "
		<< instance.limit.get()
		<< " CREATION: "
		<< dt;
	return (o);
}