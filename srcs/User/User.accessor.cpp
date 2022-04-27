/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.accessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:04:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/28 00:06:26 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

const String		User::get_username	(void) const
{
	return (this->_username);
}

const std::vector<bool>	User::get_mode		(void) const
{
	return (this->_mode);
}

bool	User::get_specific_mode	(UserMode mode) const
{
	return (this->_mode[mode]);
}

const String	User::get_realname	(void) const
{
	return (this->_realname);
}


void	User::set_username		(String username)
{
	this->_username = username;
}

void	User::set_mode	(String mode)
{
	(void)mode;
}

void	User::set_specific_mode		(UserMode mode
									,bool val)
{
	this->_mode[mode] = val;
}

void	User::set_realname		(String realname)
{
	this->_realname = realname;
}
