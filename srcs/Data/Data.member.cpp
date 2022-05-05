/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:22:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 10:25:38 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

bool	Data::_user_exist	(String nickname) const
{
	return (this->_get_user(nickname) != NULL);
}

bool	Data::_chan_exist	(String name) const
{
	return (this->_chans.find(name) != this->_chans.end());
}

void	Data::_delete_users	(void)
{
	for (USERS_IT it = this->_users.begin(), ite = this->_users.end(); it != ite; it++)
		delete (*it);
}

void	Data::_delete_channels	(void)
{
	for (CHANS_IT it = this->_chans.begin(), ite = this->_chans.end(); it != ite; it++)
		delete (it->second);
}
