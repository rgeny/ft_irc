/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:31:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 11:47:52 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_user	(std::vector<std::string> & cmd)
{
	if (this->_client->get_nickname() != "anonymous")
	{
		if (cmd.size() > 4)
		{
			std::string u(cmd[1]);
			std::string tmp = "";
			User & cur_user = static_cast<User &>(*this->_client);
			cur_user.set_username(u);
			for (size_t i = 5; i < cmd.size(); i++)
				tmp += cmd[i];
			cur_user.set_realname(tmp);
			this->set_receiver(this->_client->get_nickname());
			this->add_arg(cur_user.get_nickname() + "!" + cur_user.get_username() + "@" + this->_servername);
			std::string final_msg = this->forge(RPL_WELCOME);
			this->_client->add_to_queue(final_msg);
		}
		return (SUCCESS);
	}
	return (ERROR_CONTINUE);
}
