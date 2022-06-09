/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:08:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/09 16:46:13 by abesombes        ###   ########.fr       */
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



// void User::init_chan_usermode_vec (void)
// {
// 	this->_mode.resize(8);
// 	for (int i = 0; i < 8; i++)
// 		this->_mode[i] = false;
// }