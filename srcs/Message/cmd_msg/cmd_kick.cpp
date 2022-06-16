/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_kick.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:21:42 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/16 10:12:24 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

/*

S <-   :alice!a@localhost JOIN :#Melbourne
C  ->  KICK #Melbourne alice
S <-   :dan!d@localhost KICK #Melbourne alice :dan
dan kicking a user with no reason given

C  ->  JOIN #test
S <-   :alice!a@localhost JOIN :#test
S <-   :irc.example.com 353 alice = #test :alice @dan
S <-   :irc.example.com 366 alice #test :End of /NAMES list.
S <-   :dan!d@localhost KICK #test alice :dan
alice getting kicked with no reason given

S <-   :alice!a@localhost JOIN :#test
C  ->  kick #test alice :nah mate
S <-   :dan!d@localhost KICK #test alice :nah mate
dan kicking a user with a reason

C  ->  join #test
S <-   :alice!a@localhost JOIN :#test
S <-   :irc.example.com 353 alice = #test :alice @dan
S <-   :irc.example.com 366 alice #test :End of /NAMES list.
S <-   :dan!d@localhost KICK #test alice :nah mate
alice getting kicked with a reason given

C  ->  JOIN #test
S <-   :alice!a@localhost JOIN :#test
S <-   :irc.example.com 353 alice = #test :alice @dan
S <-   :irc.example.com 366 alice #test :End of /NAMES list.
C  ->  KICK #test dan
S <-   :irc.example.com 482 alice #test :You're not channel operator
alice kicking with no permissions

C  ->  JOIN #v3
S <-   :dan!d@Clk-830D7DDC JOIN :#v3
S <-   :irc.example.com 353 dan = #v3 :@dan
S <-   :irc.example.com 366 dan #v3 :End of /NAMES list.
C  ->  KICK #v3 tom
S <-   :irc.example.com 401 dan tom :No such nick/channel
C  ->  KICK #v3 jerry
S <-   :irc.example.com 441 dan jerry #v3 :They aren't on that channel
dan kicking a user that does not exist, and a user that isn’t on the channel

*/

e_error	Message::_cmd_kick	(String reason, String kicked, bool broadcast) const
{
	Channel::CHAN_USER_LIST *chan_ulist = NULL;
	String nickname = (*_users_it)->get_nickname();
	String	msg	= this->_set_msg_base(nickname
									+ "!"
									+ (*_users_it)->get_username()
									+ "@"
									+ (*_users_it)->get_host(), String(KICK)
                                    + " "
                                    + _cmd[1] 
                                    + " " 
                                    + kicked, 
                                    (reason != ":" ? reason : ""))
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	if (broadcast)
	{
		chan_ulist = &(*_chans_it).second->get_chan_user_list();
		if (chan_ulist && chan_ulist->size() > 0)
		{
			for (Channel::CHAN_USER_LIST::iterator it = chan_ulist->begin(), ite = chan_ulist->end(); it != ite; it++)
			{
				if (it->second != *_users_it)
					(*it).second->add_to_queue(msg);
			}
			if (kicked != nickname)
				this->_get_user(kicked)->add_to_queue(msg);
		}
	}
	return (SUCCESS);
}
