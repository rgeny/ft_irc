/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:13:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/01 19:52:30 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_part	(void)
{
    if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		if (!has_begin_hashtag(this->_cmd[1]))
		{
			return (this->_err_nosuchchannel());
		}
		else 
		{
			if (chan_exist(_cmd[1]) == false)
				return (this->_err_nosuchchannel());
			else
			{
				this->_chans_it = (this->_chans.find(_cmd[1]));
                if (user_exist_in_chan(*(*this->_chans_it).second, (*_users_it)->get_nickname()) == false)
					return (_err_notonchannel());
                Channel::CHAN_USER_LIST *tmp = NULL;
                tmp = &(*_chans_it).second->get_chan_user_list();
                
                std::cout << "nb of user deleted in chan_user_list(): " << (*tmp).erase((*_users_it)->get_nickname()) << std::endl;
                User::CHAN_USERMODE & chan_usermode = (*_users_it)->get_chan_usermode();
                std::cout << "nb of chan deleted in chan_user_mode: " << chan_usermode.erase(_chans_it->first) << std::endl;

                if (tmp->size() < 1)
                {
                    std::cout << "channel to be removed because empty: " << (*_chans_it).first << std::endl;
                    std::cout << "Channel is removed completely from server? " << _chans.erase((*_chans_it).first) << std::endl;
                }
				if (this->_cmd.size() > 2)
				{
					return (this->_cmd_part_reason());
				}
				else if (this->_cmd.size() == 2)
				{
                    return (this->_cmd_part());
				}
			}
		}
	}
	return (SUCCESS);
}