/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:22:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 20:27:41 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void	Data::_delete_users	(void)
{
	for (USERS_IT it = this->_users.begin(), ite = this->_users.end(); it != ite; it++)
		delete (*it);
}
