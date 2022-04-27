/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 12:17:05 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_join	(void)
{
	if ((*this->_msgs_it).size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		if (check_chan_name((*this->_msgs_it[1]) == false || check_chan_name(case_proof(*this->msgs_it[1])) == false)
			return (ERROR_CONTINUE);
		Channel::CHAN_USER_LIST *tmp = NULL;
		if ((_chans_it = this->_chans.find(case_proof(*this->_msgs_it[1]))) == _chans.end())
		{
			this->_chans[case_proof(*this->_msgs_it[1])] = new Channel(*this->_msgs_it[1], "");
			_chans_it = this->_chans.find(case_proof(*this->_msgs_it[1]));
		}
		tmp = &(*_chans_it).second->get_chan_user_list();
		(*tmp)[(*_users_it)->get_nickname()] = *_users_it;
		for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
			std::cout << (*it).second->get_nickname() << std::endl;
		return (this->_cmd_join());
	}
	return (SUCCESS);
}
