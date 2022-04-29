/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:32:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 06:07:24 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_ping	(void)
{
	if (this->_cmd.size() == 1)
		return (this->_err_noorigin());
	else if (this->_cmd[1] != this->_servername)
		return (this->_err_nosuchserver());
	return (this->_cmd_pong());
}
