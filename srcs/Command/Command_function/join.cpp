/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 13:22:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_join	(std::vector<std::string> & cmd)
{
	if (cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
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
