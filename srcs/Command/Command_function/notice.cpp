/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:46:32 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/15 23:12:14 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_notice	(void)
{
	bool voice = false;
	if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams());
	else
	{
		if (has_begin_hashtag(this->_cmd[1]))
		{
			if (!this->_chan_exist(_cmd[1]))
				return(_err_nosuchchannel(_cmd[1]));
			else
				_chans_it = _chans.find(_cmd[1]);
			bool moderated = _chans[_cmd[1]]->get_specific_mode(CHANMODE_m);
			Channel cur_chan = *(*_chans_it).second;
			if (user_exist_in_chan(cur_chan, _cmd[1]))
				voice = (*_users_it)->get_chan_usermode_vec(this->_cmd[1])[USERMODE_v];
			bool chan_operator = is_operator((*_users_it)->get_nickname(), cur_chan);
			bool n_activated = _chans[_cmd[1]]->get_specific_mode(CHANMODE_n);
			if (chan_operator == false && moderated == true && voice == false) 
				return (_err_cannotsendtochan("You cannot send messages to this channel whilst the +m (moderated) mode is set."));
			if (!user_exist_in_chan(cur_chan, (*_users_it)->get_nickname()) && n_activated == true)
				return (_err_cannotsendtochan("You cannot send external messages to this channel whilst the +n (noextmsg) mode is set."));
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
