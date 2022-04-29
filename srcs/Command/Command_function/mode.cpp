/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/29 19:40:54 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_mode	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
        std::cout << "I am in MODE\n";
        if (!has_begin_hashtag(this->_cmd[1]))
        {
            if (_cmd[1] != (*_users_it)->get_nickname())
                return (this->_err_usersdontmatch());
        }
        else 
        {
            if (chan_exist(_cmd[1]) == false)
            // if ((*_chans_it).second->chan_exist(_cmd[1]) == false)
                return (this->_err_nosuchchannel());
        }

		// if (check_chan_name(this->_cmd[1]) == false || check_chan_name(this->_cmd[1]) == false)
		// 	return (ERROR_CONTINUE);
		// Channel::CHAN_USER_LIST *tmp = NULL;
		// this->_chans_it = this->_chans.find(this->_cmd[1]);
		// if (this->_chans_it == _chans.end())
		// {
		// 	this->_chans[this->_cmd[1]] = new Channel(this->_cmd[1], "");
		// 	_chans_it = this->_chans.find(this->_cmd[1]);
		// 	(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), 2);
		// }
		// else
		// 	(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), 0);
		// tmp = &(*_chans_it).second->get_chan_user_list();
		// (*tmp)[(*_users_it)->get_nickname()] = *_users_it;
		// // for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
		// // 	std::cout << (*it).second->get_nickname() << std::endl;
		return (this->_cmd_mode());
	}
	return (SUCCESS);
}