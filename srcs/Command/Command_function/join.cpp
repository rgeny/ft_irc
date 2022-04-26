/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 19:04:27 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

// to be built: parsing of chan_list and chan_keys, chan_key control, 

e_error	Command::_join	(std::vector<std::string> & cmd)
{
	if (cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		if (check_chan_name(cmd[1]) == false || check_chan_name(case_proof(cmd[1])) == false)
			return (ERROR_CONTINUE);
		Channel::CHAN_USER_LIST *tmp = NULL;
		if ((_chans_it = this->_chans.find(case_proof(cmd[1]))) == _chans.end())
		{
			this->_chans[case_proof(cmd[1])] = new Channel(cmd[1], "");
			_chans_it = this->_chans.find(case_proof(cmd[1]));
		}
		tmp = &(*_chans_it).second->get_chan_user_list();
		(*tmp)[(*_users_it)->get_nickname()] = *_users_it;
		for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
		std::cout << (*it).second->get_nickname() << std::endl;
	}
	return (SUCCESS);
}
