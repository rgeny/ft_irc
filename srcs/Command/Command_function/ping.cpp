/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:32:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 18:21:27 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_ping	(std::vector<std::string> & cmd)
{
	if (cmd.size() == 1)
		return (this->_err_noorigin());
	else if (cmd[1] != this->_servername)
		return (this->_err_nosuchserver());
	return (this->_cmd_pong());
}
