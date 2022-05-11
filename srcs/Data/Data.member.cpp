/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:22:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 14:28:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

size_t	Data::_count_users	(void) const
{
	return (this->_users.size());
}

size_t	Data::_count_services	(void) const
{
	return (0);
}

size_t	Data::_count_operator	(void) const
{
	size_t	ope = 0;
	for (size_t i = 0, size = this->_users.size(); i < size; i++)
	{
		if (this->_users[i]->get_specific_mode(USERMODE_o) == true)
			ope++;
	}
	return (ope);
}

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

std::map<String, std::string>	Data::_init_ope_list	(void)
{
	std::map<String, std::string>	ope_list;

	ope_list["Ayzapata"] = "aTaPaZyA";
	ope_list["Abesombes"] = "SeBmOsEbA";
	ope_list["Rgeny"] = "YnEgR";

	return (ope_list);
}
