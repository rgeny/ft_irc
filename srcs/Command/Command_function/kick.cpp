/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:22:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/20 11:23:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_kick (void)
{
    bool broadcast = BROADCAST;
    Channel *cur_chan = (*this->_chans_it).second;
    if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams(_cmd[0]));
	else
	{
        if (this->_chan_exist(_cmd[1]) == false)
            return (_err_nosuchchannel(_cmd[1]));  
        _chans_it = _chans.find(_cmd[1]);

		if (is_operator((*_users_it)->get_nickname(), *cur_chan) == false)
            return (_err_chanoprivsneeded());
        String reason = concat_last_args(3);
        Channel::CHAN_USER_LIST *chan_ulist = NULL;
        chan_ulist = &(*_chans_it).second->get_chan_user_list();
        _nick_list = split(this->_cmd[2], ",");
        
        for (std::vector<String>::iterator it = _nick_list.begin(), ite = _nick_list.end(); it != ite; it++)
        {

            if (this->_user_exist(*it) == false)
            {
                if (it == ite - 1)
                    return (_err_nosuchnick(*it));
                else
                {
                    _err_nosuchnick(*it);
                    continue;
                }
            }
            if (user_exist_in_chan(*_chans_it->second, *it) == false)
            {
                if (it == ite - 1)
                    return (_err_usernotinchannel(*it, _chans_it->second->get_chan_name()));
                else
                {
                    _err_usernotinchannel(*it, _chans_it->second->get_chan_name());
                    continue;
                }
            }
            (*chan_ulist).erase(*it);
            User* cur_user = (this->_get_user(*it));
            String cur_chan_name = _chans_it->first;
            User::CHAN_USERMODE & chan_usermode = cur_user->get_chan_usermode();
            chan_usermode.erase(cur_chan_name);

            if (chan_ulist->size() < 1)
            {
                delete(_chans.find(cur_chan_name)->second);
                _chans.erase(cur_chan_name);
                this->_chans_it = _chans.begin();
                broadcast = NOBROADCAST;
				break;
            }

            if (it == ite - 1)
                return (_cmd_kick(reason,*it, broadcast));
            else
                _cmd_kick(reason,*it, broadcast);
        }   
    }
    return (SUCCESS);
}
