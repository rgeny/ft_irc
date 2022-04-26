/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:13:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 16:00:27 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_pass	(std::vector<std::string> & msg)
{
	if (msg.size() < 2)
		return (this->_err_needmoreparams());
	else if ((*this->_users_it).co_is_complete())
		return (this->_err_alreadyregistred());

	(*this->_users_it).set_passwd_is_sent(this->_password == msg[1]);
	if ((*this->_users_it).get_passwd_is_sent())
		return (SUCCESS);
	return (ERROR_CONTINUE);
}
