/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.accessor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:56:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/20 05:09:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

const std::string &	Client::get_nickname	(void) const
{
	return (this->_nickname);
}

bool	Client::set_nickname	(std::string nickname)
{
	char	c = nickname[0];

	if (nickname.size() > 9 || nickname.size() == 0
		|| (!isalpha(c) && !is_special(c)))
	{
		return (false);
	}
	for (int i = 1; i < 8 && i < nickname.size(); i++)
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
