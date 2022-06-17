/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:46:32 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/17 15:28:01 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

/*
NOTICE message
Command: NOTICE
Parameters: <target> <text to be sent>

*/

e_error	Command::_notice	(void)
{
	bool voice = false;
	String nickname = (*_users_it)->get_nickname();
	if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams(_cmd[0]));
	else
	{
		if (has_begin_hashtag(this->_cmd[1]))
		{
			if (!this->_chan_exist(_cmd[1]))
				return(_err_nosuchchannel(_cmd[1]));
			_chans_it = _chans.find(_cmd[1]);
			bool moderated = _chans[_cmd[1]]->get_specific_mode(CHANMODE_m);
			Channel &cur_chan = *(*_chans_it).second;
			if (user_exist_in_chan(cur_chan, _cmd[1]))
				voice = (*_users_it)->get_chan_usermode_vec(this->_cmd[1])[USERMODE_v];
			_chan_ban_list = &cur_chan.get_chan_ban_list();
			_is_on_ban_list = (_chan_ban_list->find(nickname) != _chan_ban_list->end());
			bool chan_operator = is_operator(nickname, cur_chan);
			bool n_activated = _chans[_cmd[1]]->get_specific_mode(CHANMODE_n);
			
			if (chan_operator == false && moderated == true && voice == false) 
				return (_err_cannotsendtochan(ERR_CHANMODERATED));
				
			if (chan_operator == false && _is_on_ban_list) 
				return (_err_cannotsendtochan(ERR_NOMSGWHILEBANNED));
				
			if (!user_exist_in_chan(cur_chan, nickname) && n_activated == true)
				return (_err_cannotsendtochan(ERR_CHANMODENOEXTMSG));
		}
		else if (!has_begin_hashtag(this->_cmd[1]))
		{
			if (this->_user_exist(_cmd[1]) == false)
				return (_err_nosuchnick(_cmd[1]));
		}
			String msg = concat_last_args(2);
			return (this->_cmd_notice(msg));
	}
    return (SUCCESS);
}
