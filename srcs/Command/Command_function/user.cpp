/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 14:12:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_user	(void)
{
	if (!(*this->_users_it)->get_passwd_is_sent())
		return (this->_err_passwdmismatch());
	else if (this->_cmd.size() > 4)
	{
		User & cur_user = *(*this->_users_it);

		cur_user.set_username(this->_cmd[1]);

		if (is_number(this->_cmd[2]))
		{
			long	n = strtol(this->_cmd[2].c_str(), NULL, 10);
			if (n != LONG_MAX && n != LONG_MIN)
			{
				cur_user.set_specific_mode(USERMODE_w, (n & 0x2) == 0x2);
				cur_user.set_specific_mode(USERMODE_i, (n & 0x4) == 0x4);
			}
		}

		cur_user.set_realname(this->_cmd[4]);
	}
	return (SUCCESS);
}
