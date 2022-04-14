/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.operator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:01:58 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/14 16:13:44 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

//User &	User::operator=	(User & src)
//{
//	(void)src;
//	return (*this);
//}

User & User::operator=(User const & rhs)
{
	this->username = rhs.username.get();
	this->nickname = rhs.nickname.get();
	this->hostname = rhs.hostname.get();
	this->realname = rhs.realname.get();
	this->mode = rhs.mode.get();
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,User & src)
{
	(void)src;
	return (os);
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