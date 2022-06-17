/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/18 00:25:11 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_nick	(void)
{
	String	oldest_nickname = (*this->_users_it)->get_nickname();

	if (!(*this->_users_it)->get_passwd_is_sent())
		return (this->_err_passwdmismatch());
	else if (this->_cmd.size() <= 1)
		return (this->_err_nonicknamegiven());
	else if (oldest_nickname != this->_cmd[1]
			&& this->_nick_already_used(this->_cmd[1]))
	{
		return (this->_err_nicknameinuse());
	}
	else if (oldest_nickname != this->_historical.find_actual(this->_cmd[1])
			&& this->_historical.nick_is_lock(this->_cmd[1]))
	{
		return (this->_err_unavailresource());
	}
	else if ((*this->_users_it)->get_specific_mode(USERMODE_r))
		return (this->_err_restricted());
	else if ((*this->_users_it)->set_nickname(this->_cmd[1]) == false)
		return (this->_err_erroneusnickname());
	this->update_all_nickname_records(oldest_nickname, _cmd[1]);
	this->_historical.new_node(oldest_nickname, this->_cmd[1]);
	this->_cmd_nick(oldest_nickname);
	return (SUCCESS);
}
