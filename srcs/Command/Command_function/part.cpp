/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:13:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/04 21:48:20 by rgeny            ###   ########.fr       */
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
			if (this->_chan_exist(_cmd[1]) == false)
				return (this->_err_nosuchchannel());
			else
			{
				this->_chans_it = (this->_chans.find(_cmd[1]));
                if (user_exist_in_chan(*(*this->_chans_it).second, (*_users_it)->get_nickname()) == false)
					return (_err_notonchannel());
                Channel::CHAN_USER_LIST *tmp = NULL;
                tmp = &(*_chans_it).second->get_chan_user_list();
                
                (*tmp).erase((*_users_it)->get_nickname());
                User::CHAN_USERMODE & chan_usermode = (*_users_it)->get_chan_usermode();
                chan_usermode.erase(_chans_it->first);

                if (tmp->size() < 1)
                    _chans.erase((*_chans_it).first);
				String reason;
				if (this->_cmd.size() > 2)
					reason = concat_last_args(2);
                return (this->_cmd_part(reason));
			}
		}
	}
	return (SUCCESS);
}
