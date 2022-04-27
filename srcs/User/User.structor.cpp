/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.structor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:35:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:40:16 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User:: User	(void)
	:_username(DFL_USERNAME)
	,_realname(DFL_REALNAME)
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
{
	(void)src;
	std::cout	<< "User cpy constructor."
				<< std::endl;
}

User::~User	(void)
{
	std::cout	<< "User destructor."
				<< std::endl;
}

