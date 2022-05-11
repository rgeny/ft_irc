/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:13:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 13:58:49 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_pass	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else if (static_cast<User *>((*this->_users_it))->co_is_complete())
		return (this->_err_alreadyregistred());

	(*this->_users_it)->set_passwd_is_sent(this->_password == this->_cmd[1].c_str());
	if ((*this->_users_it)->get_passwd_is_sent())
		return (SUCCESS);
	this->_err_passwdmismatch();
	return (ERROR_CONTINUE);
}
