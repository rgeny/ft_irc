/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:41:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 06:21:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::CMD_FCT	Command::_cmds_fct;

Command:: Command	(void)
	:Data()
	,Message()
{
	std::cout	<< "Command dfl constructor."
				<< std::endl;
	this->_init_cmd_fct();
}

Command:: Command	(Command & src)
	:Data()
	,Message()
{
	std::cout	<< "Command cpy constructor."
				<< std::endl;
	this->_init_cmd_fct();
	(void)src;
}

Command::~Command	(void)
{
	std::cout	<< "Command destructor."
				<< std::endl;
}


