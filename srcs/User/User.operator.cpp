/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.operator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:45:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 09:51:50 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User &	User::operator=	(User & src)
{
	this->_username = src._username;
	this->_mode = src._mode;
	this->_realname = src._realname;
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,User & src)
{
	os	<< "nickname : "
		<< src.get_nickname()
		<< std::endl
		<< "username : "
		<< src.get_username()
		<< std::endl
		<< "mode :"
		<< std::endl;
	const char	*usermode[] =
		{"a", "i", "w", "r"
		,"o", "O", "s"};
	for (int i = 0; i < 7; i++)
	{
		os	<< usermode[i]
			<< " : "
			<< std::boolalpha
			<< src.get_mode()[i]
			<< std::endl;
	}
	os	<< "realname : "
		<< src.get_realname()
		<< std::endl;
	
	return (os);
}

