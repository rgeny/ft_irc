/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:44:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/05 11:23:55 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

/*
 Command: PRIVMSG
  Parameters: <target>{,<target>} <text to be sent>
The PRIVMSG command is used to send private messages between users, as well as to send messages to channels. <target> is the nickname of a client or the name of a channel.
*/

e_error	Command::_privmsg	(void)
{
    if (this->_cmd.size() < 3)
      return (this->_err_needmoreparams());
    else
    {
        if (has_begin_hashtag(this->_cmd[1]))
        {
          if (!this->_chan_exist(_cmd[1]))
			      return(_err_nosuchchannel());
          bool moderated = _chans[_cmd[1]]->get_specific_mode(CHANMODE_m);
          bool voice = (*_users_it)->get_specific_mode(USERMODE_v);
          bool chan_operator = is_operator((*_users_it)->get_nickname(), *_chans_it->second);
          if (chan_operator == false && moderated == true && voice == false)
            return (_err_cannotsendtochan("You cannot send messages to this channel whilst the +m (moderated) mode is set."));
        }
          String msg = concat_last_args(2);
          return (this->_cmd_privmsg(msg));
      }
    return (SUCCESS);
}
