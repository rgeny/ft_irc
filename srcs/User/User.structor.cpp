/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.structor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:35:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/02 13:00:03 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User:: User	(void)
	:_username(DFL_USERNAME)
	,_realname(DFL_REALNAME)
	,_host("10.13.2.14")
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
	,_host("10.13.2.14")
{
	(void)mode;

	this->_mode.resize(8);
	for (int i = 0; i < 8; i++)
		this->_mode[i] = false;
//	this->_mod[USERMODE_w] = (mode == "2" || mode == "6");
//	this->_mod[USERMODE_i] = (mode == "6" || mode == "4");
}

User:: User	(User const & src)
	:Client()
	,_username(src._username)
	,_mode(src._mode)
	,_realname(src._realname)
	, _host("10.13.2.14")
{
	std::cout	<< "User cpy constructor."
				<< std::endl;
}

User::~User	(void)
{
	std::cout	<< "User destructor."
				<< std::endl;
}

