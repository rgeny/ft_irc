/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.accessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:04:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 17:06:59 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

const std::string			User::get_username	(void) const
{
	return (this->_username);
}

const std::vector<bool>		User::get_mode		(void) const
{
	return (this->_mode);
}

bool	User::get_specific_mode	(UserMode mode) const
{
	return (this->_mode[mode]);
}

const std::string			User::get_realname	(void) const
{
	return (this->_realname);
}


void	User::set_username		(std::string username)
{
	this->_username = username;
}

void	User::set_mode			(std::string mode)
{
	(void)mode;
}

void	User::set_specific_mode	(UserMode mode
								,bool val)
{
	this->_mode[mode] = val;
}

void	User::set_realname		(std::string realname)
{
	this->_realname = realname;
}

void	User::set_chan_usermode	(std::string chan
							,int mode)
{
	std::vector<bool> tmp_vb(3, 0);
	int i = 2;
	while (i >= 0)
	{
		tmp_vb[2 - i] = mode >> i;
		i--;
	}

	if (this->_chan_usermode.find(chan) == _chan_usermode.end())
	{
		this->_chan_usermode[chan] = tmp_vb;
	}

}

std::vector<bool> User::get_chan_usermode(std::string chan_name)
{
	return (_chan_usermode[chan_name]);
}