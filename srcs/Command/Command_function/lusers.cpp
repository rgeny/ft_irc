/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lusers.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:10:55 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 19:46:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_lusers	(void)
{
	if (this->_cmd.size() > 2
		&& this->_cmd[2] != this->_servername)
	{
		this->_cmd[1] = this->_cmd[2];
		return (this->_err_nosuchserver());
	}
	this->_rpl_luserclient();
	this->_rpl_luserop();
//	this->_rpl_luserunknown();
	this->_rpl_luserchannels();
	this->_rpl_luserme();
	return (SUCCESS);
}
