/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.structor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:35:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/21 10:26:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User:: User	(void)
	:_username(DFL_USERNAME)
	,_realname(DFL_REALNAME)
	,_host("127.0.0.1")
{
	this->_mode.resize(8);
	for (int i = 0; i < 8; i++)
		this->_mode[i] = false;
	std::cout	<< "User dfl constructor."
				<< std::endl;
}

User:: User	(String	nickname
			,String	username
			,String	mode
			,String	realname)
	:Client(nickname)
	,_username(username)
	,_realname(realname)
	,_host("127.0.0.1")
{
	(void)mode;

	this->_mode.resize(8);
	for (int i = 0; i < 8; i++)
		this->_mode[i] = false;
//	this->_mod[USERMODE_w] = (mode == "2" || mode == "6");
//	this->_mod[USERMODE_i] = (mode == "6" || mode == "4");
	std::cout	<< "User parameters constructor."
				<< std::endl;
}

User:: User	(User const & src)
	:Client()
	,_username(src._username)
	,_mode(src._mode)
	,_realname(src._realname)
	, _host("127.0.0.1")
{
	std::cout	<< "User cpy constructor."
				<< std::endl;
}

User::~User	(void)
{
	std::cout	<< "User destructor."
				<< std::endl;
}

