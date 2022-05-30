/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motd.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:31:19 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_motd	(void)
{
	if (this->_cmd.size() == 1)
		return (this->_cmd_motd());
	else
	{
		if (this->_servername == _cmd[1])
			return (this->_cmd_motd());
		else
			return (_err_nosuchserver());
	}
	return (SUCCESS);
}