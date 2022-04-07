/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:10:14 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 16:21:33 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/User.hpp"

User::User()
	:
	username(""),
	nickname(""),
	hostname(""),
	realname(""),
	mode("")
{
	// std::cout << "Default constructor User" << std::endl;
}

User::User(	std::string const & username,
			std::string const & nickname,
			std::string const & hostname,
			std::string const & realname,
			std::string const & mode )
	:
	username(username),
	nickname(nickname),
	hostname(hostname),
	realname(realname),
	mode(mode)
{
	// std::cout << "Parameterized constructor User" << std::endl;
}

User::User( User const & src)
	:
	username(src.username.get()),
	nickname(src.nickname.get()),
	hostname(src.hostname.get()),
	realname(src.realname.get()),
	mode(src.mode.get())
{
	// std::cout << "Copy constructor User" << std::endl;
}

User & User::operator=(User const & rhs)
{
	this->username = rhs.username.get();
	this->nickname = rhs.nickname.get();
	this->hostname = rhs.hostname.get();
	this->realname = rhs.realname.get();
	this->mode = rhs.mode.get();
	return (*this);
}

User::~User()
{
	// std::cout << "Destructor User" << std::endl;
}


std::ostream&	operator<<( std::ostream& o, User const & instance)
{
	o	<< "USER"
		<< " USERNAME: "
		<< instance.username.get()
		<< " NICKNAME: "
		<< instance.nickname.get()
		<< " HOSTNAME: "
		<< instance.hostname.get()
		<< " REALNAME: "
		<< instance.realname.get()
		<< " MODE: "
		<< instance.mode.get();
	return (o);
}