/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:32:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 04:34:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

int		Command::_ping	(std::vector<std::string> & cmd)
{
	std::string		code = PONG;
	std::string		final_msg;

	if (cmd.size() == 1)
		code = ERR_NOORIGIN;
	else
	{
		if (cmd[1] == this->_data._servername)
			this->_reply.add_arg(this->_data._servername);
		else
			code = ERR_NOSUCHSERVER;
		this->_reply.add_arg(cmd[1]);
	}
	final_msg = this->_reply.forge(code);
	this->_client->add_to_queue(final_msg);
	return (-(code == PONG));
}
