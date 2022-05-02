/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userhost.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:04:22 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/02 15:29:52 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_userhost	(void)
{
	if (this->_cmd.size() == 1)
		return (_err_needmoreparams());
	else
	{
		String userhost_list;
		int i = 0;

		for (CMD::iterator it = _cmd.begin() + 1; it != _cmd.end() && it != _cmd.begin() + 6; it++)
		{
			std::cout << "User to userhost: " << *it << std::endl; 
			if (user_exist(*it) == true)
			{
				if (i > 0)
					userhost_list += " ";
				i++;
				userhost_list += get_user(*it)->get_nickname() + "=+~" + get_user(*it)->get_username() + "@" + get_user(*it)->get_host();
			}
				
		}
		return (_cmd_userhost(userhost_list));
	}
	return (SUCCESS);
}