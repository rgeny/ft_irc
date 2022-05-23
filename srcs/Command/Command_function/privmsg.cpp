/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:44:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/23 10:32:13 by abesombe         ###   ########.fr       */
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
  bool voice = false;
    if (this->_cmd.size() < 3)
      return (this->_err_needmoreparams());
    else
    {
        if (has_begin_hashtag(this->_cmd[1]))
        {
          if (!this->_chan_exist(_cmd[1]))
			      return(_err_nosuchchannel());
	        this->_chans_it = this->_chans.find(_cmd[1]);
          bool moderated = _chans[_cmd[1]]->get_specific_mode(CHANMODE_m);
          Channel & cur_chan = *((*_chans_it).second);
          if (user_exist_in_chan(cur_chan, _cmd[1]))
             voice = (*_users_it)->get_chan_usermode_vec(this->_cmd[1])[USERMODE_v];
          bool chan_operator = is_operator((*_users_it)->get_nickname(), *_chans_it->second);
          bool n_activated = _chans[_cmd[1]]->get_specific_mode(CHANMODE_n);
          if (chan_operator == false && moderated == true && voice == false) 
            return (_err_cannotsendtochan("You cannot send messages to this channel whilst the +m (moderated) mode is set."));
          if (!user_exist_in_chan(cur_chan, (*_users_it)->get_nickname()) && n_activated == true)
          {
            std::cout << "cur_user: " << (*_users_it)->get_nickname() << std::endl;
            std::cout << "cur_chan: " << cur_chan.get_chan_name() << std::endl;            
            return (_err_cannotsendtochan("You cannot send external messages to this channel whilst the +n (noextmsg) mode is set."));
          }
        }
        else if (!has_begin_hashtag(this->_cmd[1]))
        {
          if (this->_user_exist(_cmd[1]) == false)
            return (_err_nosuchnick());
        }
          String msg = concat_last_args(2);
          return (this->_cmd_privmsg(msg));
      }
    return (SUCCESS);
}
