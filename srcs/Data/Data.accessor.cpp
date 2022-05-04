/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.accessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:28:12 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 21:20:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

User *	Data::_get_user	(String nickname) const
{
	size_t	n_user = this->_users.size();
	for (size_t i = 0; i < n_user; i++)
	{
		if (this->_users[i]->get_nickname() == nickname)
			return (this->_users[i]);
	}
	return (NULL);
}
