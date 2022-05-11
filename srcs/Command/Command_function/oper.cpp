/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:34:26 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 16:16:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_oper	(void)
{
	if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams());
	if (this->_ope_list.find(this->_cmd[1]) == this->_ope_list.end())
		return (this->_err_nooperhost());
	if (this->_ope_list[this->_cmd[1]] != this->_cmd[2].c_str())
	{
		this->_err_passwdmismatch();
		return (ERROR_CONTINUE);
	}
	(*this->_users_it)->set_specific_mode(USERMODE_o, true);
//	this->_cmd.clear();
//	this->_cmd.push_back(MODE);
//	this->_cmd.push_back((*this->_users_it)->get_nickname());
//	this->_mode();
	return (this->_rpl_youreoper());
}
