/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 15:58:46 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_nick	(std::vector<std::string> & cmd)
{
	std::string	oldest_nickname = (*this->_users_it).get_nickname();

	if (!(*this->_users_it).get_passwd_is_sent())
		return (this->_err_passwdmismatch());
	else if (cmd.size() <= 1)
		return (this->_err_nonicknamegiven());
	else if (oldest_nickname != cmd[1]
			&& this->_nick_already_used(cmd[1]))
	{
		return (this->_err_nicknameinuse());
	}
	else if (oldest_nickname != this->_historical.find_actual(cmd[1])
			&& this->_historical.nick_is_lock(cmd[1]))
	{
		return (this->_err_unavailresource());
	}
	else if ((*this->_users_it).get_specific_mode(USERMODE_r))
		return (this->_err_restricted());
	else if ((*this->_users_it).set_nickname(cmd[1]) == false)
		return (this->_err_erroneusnickname());
	this->_historical.new_node(oldest_nickname, cmd[1]);
	return (SUCCESS);
}
