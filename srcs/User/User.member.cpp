/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:08:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 14:40:04 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

bool	User::co_is_complete	(void) const
{
	return (this->get_nickname() != DFL_NICKNAME
			&& this->get_username() != DFL_USERNAME
			&& this->get_realname() != DFL_REALNAME);
}
