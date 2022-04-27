/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:30:04 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_user	(void)
{
	if ((*this->_users_it)->get_nickname() != "anonymous")
	{
		if ((*this->_msgs_it).size() > 4)
		{
			User & cur_user = *(*this->_users_it);

			cur_user.set_username((*this->_msgs_it)[1]);
		
			//tmp
			String	tmp;
			size_t	size = (*this->_msgs_it).size();
			for (size_t i = 4; i < size; i++)
				tmp += (*this->_msgs_it)[i];
			//fin tmp
			std::cout	<< "realname : "
						<< tmp
						<< "\n";
			cur_user.set_realname(tmp);

			return (this->_rpl_welcome());
		}
		return (SUCCESS);
	}
	return (ERROR_CONTINUE);
}
