/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:16 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 15:37:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_pong	(void)
{
	String	tmp = ":"
				+ this->_servername;
	if (this->_cmd[1] == tmp)
		this->_tmp_users.erase(*this->_users_it);
	return (SUCCESS);
}
