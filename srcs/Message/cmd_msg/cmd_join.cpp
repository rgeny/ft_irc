/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:52:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/20 13:48:54 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

e_error	Message::_cmd_join	(void) const
{
/*
C  ->  JOIN #test
S <-   :dan!~d@0::1 JOIN #test
S <-   :irc.example.com MODE #test +nt
S <-   :irc.example.com 332 alice #test :This is my cool channel! https://irc.com
S <-   :irc.example.com 333 alice #test dan!~d@localhost 1547691506
S <-   :irc.example.com 353 dan = #test :@dan
S <-   :irc.example.com 366 dan #test :End of /NAMES list.
*/
	Channel::CHAN_USER_LIST *chan_ulist = NULL;
	Channel *cur_chan = (*this->_chans_it).second;
	String	msg	= this->_set_msg_base((*_users_it)->get_nickname() 
									+ "!"
									+ (*_users_it)->get_username()
									+ "@"
									+ (*_users_it)->get_host(), JOIN, ":"
									+ this->_cmd[1])
									+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	chan_ulist = &(*_chans_it).second->get_chan_user_list();
	for (Channel::CHAN_USER_LIST::iterator it = chan_ulist->begin(), ite = chan_ulist->end(); it != ite; it++)
	{
		if ((*it).second != *_users_it)
		{
			String	msg	= this->_set_msg_base((*_users_it)->get_nickname()
											+ "!" + (*_users_it)->get_username()
											+ "@" + (*_users_it)->get_host(), JOIN, ":"
											+ this->_cmd[1])
											+ "\r\n";
			(*it).second->add_to_queue(msg);
		}
	}
	String name_list;
	chan_ulist = &(*_chans_it).second->get_chan_user_list();
	for (Channel::CHAN_USER_LIST::iterator it = chan_ulist->begin(); it != chan_ulist->end(); it++)
	{
		if (it != chan_ulist->begin())
			name_list += " ";
		if ((*it).second != NULL && (*it).second->get_chan_usermode().size() > 0 && (*it).second->get_chan_usermode_vec(this->_cmd[1])[USERMODE_o] == true)
			name_list += "@";
		name_list += (*it).second->get_nickname();
	}
	if (cur_chan->has_topic())
	{
		_rpl_topic();
		_rpl_topicwhotime();
	}

	_rpl_namreply(name_list);
	_rpl_endofnames(false);
	return (SUCCESS);
}
