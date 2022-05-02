/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:04:22 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/01 14:40:17 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_time	(void)
{
	if (this->_cmd.size() == 1)
	{
		return (this->_cmd_time());
	}
	return (SUCCESS);
}