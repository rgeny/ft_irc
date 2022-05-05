/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 11:10:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_user	(void)
{
	if ((*this->_users_it)->get_nickname() != "anonymous")
	{
		if (this->_cmd.size() > 4)
		{
			User & cur_user = *(*this->_users_it);

			cur_user.set_username(this->_cmd[1]);
		
			//tmp
			String	tmp;
			size_t	size = this->_cmd.size();
			for (size_t i = 4; i < size; i++)
				tmp += this->_cmd[i];
			//fin tmp
			std::cout	<< "realname : "
						<< tmp
						<< "\n";
			cur_user.set_realname(tmp);
			
//			this->_rpl_welcome();
//			this->_rpl_yourhost();
//			this->_rpl_created();
//			this->_rpl_myinfo();
//			return (this->_rpl_lcome());
		}
		return (SUCCESS);
	}
	return (ERROR_CONTINUE);
}
