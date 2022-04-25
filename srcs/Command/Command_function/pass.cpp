/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:13:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 17:43:46 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_pass	(std::vector<std::string> & msg)
{
	if (msg.size() < 2)
		return (this->_err_needmoreparams());
	else if (static_cast<User *>(this->_client)->co_is_complete())
		return (this->_err_alreadyregistred());

	this->_client->set_passwd_is_sent(this->_password == msg[1]);
	if (this->_client->get_passwd_is_sent())
		return (SUCCESS);
	return (ERROR_CONTINUE);
}
