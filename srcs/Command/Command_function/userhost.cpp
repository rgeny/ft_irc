/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userhost.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:04:22 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/17 15:28:25 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_userhost	(void)
{
	if (this->_cmd.size() == 1)
		return (_err_needmoreparams(_cmd[0]));
	else
	{
		String userhost_list;
		int i = 0;

		for (CMD::iterator it = _cmd.begin() + 1; it != _cmd.end() && it != _cmd.begin() + 6; it++)
		{
			std::cout << "User to userhost: " << *it << std::endl; 
			if (this->_user_exist(*it) == true)
			{
				if (i > 0)
					userhost_list += " ";
				i++;
				userhost_list += this->_get_user(*it)->get_nickname() + "=+~" + this->_get_user(*it)->get_username() + "@" + this->_get_user(*it)->get_host();
			}
				
		}
		return (_cmd_userhost(userhost_list));
	}
	return (SUCCESS);
}
