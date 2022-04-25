/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.operator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:19:30 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 20:28:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data &	Data::operator=	(Data & src)
{
	if (this == &src)
		return (*this);

	this->_delete_users();
	for (USERS_IT it = src._users.begin(), ite = src._users.end(); it != ite; it++)
		this->_users.push_back(new User(**it));

	this->_servername = src._servername;
	this->_hostname = src._hostname;
	this->_password = src._password;
	this->_historical = src._historical;

	return (*this);
}
