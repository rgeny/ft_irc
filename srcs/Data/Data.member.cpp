/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:22:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 21:21:38 by rgeny            ###   ########.fr       */
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
