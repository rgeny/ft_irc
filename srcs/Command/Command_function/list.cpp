/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:05:19 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 15:42:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "Utils.hpp"

e_error	Command::_list	(void)
{
	std::vector<String>	list;
	if (this->_cmd.size() == 1)
		list = this->_find_chan("*");
	else
	{
		std::vector<String>	to_find = split(this->_cmd[1], ",");
		for (size_t i = 0; i < to_find.size(); i++)
		{
			std::vector<String>	tmp = this->_find_chan(to_find[i]);
			for (size_t j = 0; j < tmp.size(); j++)
			{
				if (find(list.begin(), list.end(), tmp[j]) == list.end())
					list.push_back(tmp[j]);
			}
		}
	}
	std::cout	<< "list :\n";
	for (size_t i = 0; i < list.size(); i++)
		std::cout	<< list[i]
					<< std::endl;


	String	msg	= this->_set_reply_base(RPL_LIST);
	for (size_t i = 0; i < list.size() && msg.size() < 511; i++)
	{
		if (i != 0)
			msg += " ";
		msg += list[i]
			+ ":"
			+ this->_chans[list[i]]->get_topic();
	}
	msg	+= "\r\n";
	if (msg.size() > 512)
		return (this->_err_toomanymatches());
	(*this->_users_it)->add_to_queue(msg);
	msg	= this->_set_reply_base(RPL_LISTEND)
		+ ":end of LIST\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
