/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:13:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 18:32:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_pass	(void)
{
	if ((*this->_msgs_it).size() < 2)
		return (this->_err_needmoreparams());
	else if (static_cast<User *>((*this->_users_it))->co_is_complete())
		return (this->_err_alreadyregistred());

	(*this->_users_it)->set_passwd_is_sent(this->_password == (*this->_msgs_it)[1]);
	if ((*this->_users_it)->get_passwd_is_sent())
		return (SUCCESS);
	return (ERROR_CONTINUE);
}
