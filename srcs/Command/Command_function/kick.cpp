/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:22:23 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/03 17:26:47 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_kick	(void)
{
    if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams());
	else
	{
        if (chan_exist(_cmd[1]) == false)
            return (this->_err_nosuchchannel());
        this->_chans_it = this->_chans.find(_cmd[1]);
		if (is_operator((*_users_it)->get_nickname(), *(*this->_chans_it).second) == false)
            return (this->_err_chanoprivsneeded());
        Channel cur_chan = *(*_chans_it).second;
        if (user_exist(_cmd[2]) == false)
             return (this->_err_nosuchnick());       
        if (user_exist_in_chan(cur_chan, _cmd[2]) == false)
            return (this->_err_usernotinchannel());
        return (this->_cmd_kick(""));
        //ERR_NOSUCHNICK. If the user to be kicked exists but is not on the channel, the chanop is sent ERR_USERNOTINCHANNEL. And if the channel does not exist, ERR_NOSUCHCHANNEL is returned.
    }
    return (SUCCESS);
}