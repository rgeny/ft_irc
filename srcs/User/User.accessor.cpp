/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.accessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:04:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/09 22:33:12 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

const String		User::get_username	(void) const
{
	return (this->_username);
}

const String		User::get_user_details	(void) const
{
	String whoisuser;

	whoisuser += "~";	
	whoisuser += this->get_username();
	whoisuser += " ";
	whoisuser += this->get_host();
	whoisuser += " * :";
	whoisuser += this->get_realname();
	return (whoisuser);
}

String		User::get_user_moredetail	(String hostname, String chan_name)
{
	String whoisuser;

	whoisuser += "~";	
	whoisuser += this->get_username();
	whoisuser += " ";
	whoisuser += this->get_host();
	whoisuser += " ";
	whoisuser += hostname;
	whoisuser += " ";
	whoisuser += this->get_nickname();
	whoisuser += " H";
	if (this->get_chan_usermode().size() > 0) // Active user is member of at least one channel
	{
	 	if (this->get_chan_usermode_vec(chan_name)[USERMODE_o] == true)
			whoisuser += "@";
	}
	whoisuser += "s :0 ";
	whoisuser += this->get_realname();
	return (whoisuser);
}


String		User::get_last_joined_chan (void)
{
	return (_last_joined_chan);
}

String		User::get_user_chan_list	(void)
{
	String user_chan_list;
	CHAN_USERMODE chan_usermode;
	
	// :*.freenode.net 319 abesombes Morgawr :@#ufeff #vidyadev
	
	chan_usermode = this->get_chan_usermode();
	if (chan_usermode.size() > 0)
		user_chan_list += ":";
	for (CHAN_USERMODE::iterator it = chan_usermode.begin(), ite = chan_usermode.end(); it != ite; it++)
	{
		if (it != chan_usermode.begin())
			user_chan_list += " ";
		if (this->get_chan_usermode_vec((*it).first)[USERMODE_o] == true)
			user_chan_list += "@";
		user_chan_list += (*it).first;
	}

	return (user_chan_list);
}

const String		User::get_host	(void) const
{
	return (this->_host);
}

const std::vector<bool>	User::get_mode		(void) const
{
	return (this->_mode);
}

bool	User::get_specific_mode	(UserMode mode) const
{
	return (this->_mode[mode]);
}

bool	User::get_specific_mode	(size_t mode) const
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

void	User::set_specific_mode		(size_t mode
									,bool val)
{
	this->_mode[mode] = val;
}

void	User::set_realname		(String realname)
{
	this->_realname = realname;
}

void	User::set_chan_usermode	(String chan
							, UserMode mode
							, bool val)
{
		MODE_VEC & mode_vec = _chan_usermode[chan];
		mode_vec.resize(8);
		mode_vec[mode] = val;
}

void	User::set_chan_usermode	(String chan
							, size_t mode
							, bool val)
{
		MODE_VEC & mode_vec = _chan_usermode[chan];
		mode_vec.resize(8);
		mode_vec[mode] = val;
}

std::vector<bool> User::get_chan_usermode_vec(String chan_name)
{
	return (_chan_usermode[chan_name]);
}


User::CHAN_USERMODE & User::get_chan_usermode( void )
{
	return (_chan_usermode);
}

void	User::set_last_joined_chan(String last_joined_chan)
{
	this->_last_joined_chan = last_joined_chan;
}