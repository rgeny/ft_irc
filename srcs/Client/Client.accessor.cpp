/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.accessor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:56:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/12 18:58:44 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

const std::string &	Client::get_nickname	(void) const
{
	return (this->_nickname);
}

bool	is_available_start(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'));
}

bool	is_available	(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')
			|| (c >= 0x5B && c <= 0x60)
			|| (c >= 0x7B && c <= 0x7D)
			|| c == '-');
}

void	Client::set_nickname	(std::string nickname)
{
	if (nickname.size() > 9 || nickname.size() == 0
		|| !is_available_start(nickname[0]))
	{
		return ;
	}
	for (int i = 1; i < 8; i++)
	{
		if (!is_available(nickname[i]))
			return ;
	}
	this->_nickname = nickname;
}
