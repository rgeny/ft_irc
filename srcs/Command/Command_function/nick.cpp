/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:29:45 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_nick	(void)
{
	MSG &	msg = (*this->_msgs_it);
	String	oldest_nickname = (*this->_users_it)->get_nickname();

	if (!(*this->_users_it)->get_passwd_is_sent())
		return (this->_err_passwdmismatch());
	else if (msg.size() <= 1)
		return (this->_err_nonicknamegiven());
	else if (oldest_nickname != msg[1]
			&& this->_nick_already_used(msg[1]))
	{
		return (this->_err_nicknameinuse());
	}
	else if (oldest_nickname != this->_historical.find_actual(msg[1])
			&& this->_historical.nick_is_lock(msg[1]))
	{
		return (this->_err_unavailresource());
	}
	else if ((*this->_users_it)->get_specific_mode(USERMODE_r))
		return (this->_err_restricted());
	else if ((*this->_users_it)->set_nickname(msg[1]) == false)
		return (this->_err_erroneusnickname());
	this->_historical.new_node(oldest_nickname, msg[1]);
	return (SUCCESS);
}
