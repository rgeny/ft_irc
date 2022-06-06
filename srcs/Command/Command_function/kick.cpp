/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:22:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/06 16:11:24 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_kick (void)
{
    Channel *cur_chan = NULL;
    if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams());
	else
	{
        if (this->_chan_exist(_cmd[1]) == false)
            return (_err_nosuchchannel());  
        _chans_it = _chans.find(_cmd[1]);
        cur_chan = (*this->_chans_it).second;
		if (is_operator((*_users_it)->get_nickname(), *cur_chan) == false)
            return (_err_chanoprivsneeded());
        if (this->_user_exist(_cmd[2]) == false)
             return (_err_nosuchnick());
        if (user_exist_in_chan(*_chans_it->second, _cmd[2]) == false)
            return (_err_usernotinchannel());
        String reason = concat_last_args(3);
        Channel::CHAN_USER_LIST *chan_ulist = NULL;
        *chan_ulist = cur_chan->get_chan_user_list();
        
        chan_ulist->erase((this->_get_user(_cmd[2]))->get_nickname());
        User::CHAN_USERMODE & chan_usermode = (this->_get_user(_cmd[2]))->get_chan_usermode();
        chan_usermode.erase(_chans_it->first);

        if (chan_ulist->size() < 1)
            _chans.erase((*_chans_it).first);
        return (_cmd_kick(reason,_cmd[2]));       
    }
    return (SUCCESS);
}
