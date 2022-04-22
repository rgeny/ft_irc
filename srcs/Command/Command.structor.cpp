/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:41:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/22 14:59:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::CmdsFct	Command::_cmds_fct;

Command:: Command	(std::vector<User *> & users)
	:_users(users)
{
	std::cout	<< "Command dfl constructor."
				<< std::endl;
	this->_init_cmd_fct();
}

Command:: Command	(Command & src)
	:_users(src._users)
{
	(void)src;
	std::cout	<< "Command cpy constructor."
				<< std::endl;
	this->_init_cmd_fct();
}

Command::~Command	(void)
{
	std::cout	<< "Command destructor."
				<< std::endl;
}


