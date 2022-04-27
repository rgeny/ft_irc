/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:08:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 15:04:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

bool	User::co_is_complete	(void) const
{
	return (this->get_nickname() != DFL_NICKNAME
			&& this->get_passwd_is_sent()
			&& this->_username != DFL_USERNAME
			&& this->_realname != DFL_REALNAME);
}
