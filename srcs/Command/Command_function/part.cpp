/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:13:29 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/31 16:16:43 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error		Command::_part	(void)
{
	std::vector<String> chan_list;
	User::CHAN_USERMODE chan_usermode;

	bool user_already_in_channel = false;
	Channel *cur_chan = (*this->_chans_it).second;

	chan_list = split(this->_cmd[1], ",");
    if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		for (std::vector<String>::iterator it = chan_list.begin(), ite = chan_list.end(); it != ite; it++)
		{
			_cmd[1] = *it;
			if (!has_begin_hashtag(*it) || this->_chan_exist(*it) == false)
			{	
				if (it == ite - 1)
					return (_err_nosuchchannel());
				else
				{
					_err_nosuchchannel();
					continue;
				}
			}
			else
			{
				this->_chans_it = (this->_chans.find(*it));
				cur_chan = (*this->_chans_it).second;
				if (user_exist_in_chan(*cur_chan, (*_users_it)->get_nickname()) == false)
				{
					if (it == ite - 1)
						return (_err_notonchannel());
					else
					{
						_err_notonchannel();
						continue;
					}
				}	
				Channel::CHAN_USER_LIST *tmp = NULL;
				tmp = &cur_chan->get_chan_user_list();
				
				(*tmp).erase((*_users_it)->get_nickname());
				User::CHAN_USERMODE & chan_usermode = (*_users_it)->get_chan_usermode();
				chan_usermode.erase(_chans_it->first);

				String reason;
				if (this->_cmd.size() > 2)
					reason = concat_last_args(2);
				this->_cmd_part(reason);
				if (tmp->size() < 1)
				{
					delete (cur_chan);
					_chans.erase((*_chans_it).first);
				}
			}
		}
	}
	return (SUCCESS);
}
