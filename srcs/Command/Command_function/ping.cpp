/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:32:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 18:30:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_ping	(void)
{
	if ((*this->_msgs_it).size() == 1)
		return (this->_err_noorigin());
	else if ((*this->_msgs_it)[1] != this->_servername)
		return (this->_err_nosuchserver());
	return (this->_cmd_pong());
}
