/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.accessor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:56:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

const String &	Client::get_nickname	(void) const
{
	return (this->_nickname);
}

bool	Client::set_nickname	(String nickname)
{
	char	c = nickname[0];

	if (nickname.size() > 9 || nickname.size() == 0
		|| (!isalpha(c) && !is_special(c)))
	{
		return (false);
	}
	for (size_t i = 1; i < 8 && i < nickname.size(); i++)
	{
		c = nickname[i];
		if (!isalnum(c)
			&& !is_special(c)
			&& c != '-')
		{
			return (false);
		}
	}
	this->_nickname = nickname;
	return (true);
}

bool	Client::get_passwd_is_sent	(void) const
{
	return (this->_passwd_is_sent);
}

void	Client::set_passwd_is_sent	(bool new_val)
{
	this->_passwd_is_sent = new_val;
}

time_t	Client::get_t_last_msg	(void) const
{
	return (this->_t_last_msg);
}
