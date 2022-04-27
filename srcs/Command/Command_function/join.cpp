/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 16:25:27 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

/*

A JOIN message may also be sent from the server to indicate that someone has joined a channel. In this case, the <prefix> indicates the user that’s joined. If a user’s JOIN command is successful, they receive one of these messages. In addition, all other clients also receive a JOIN message. For example, if dan and alice are on the channel #toast, and barry joins #toast, then dan and alice will receive a JOIN message indicating that barry has joined the channel.

Whether or not the join request succeeds depends on the channel modes currently set. The key, client limit, ban/exemption, invite-only/exemption, and other channel modes can prevent clients from joining a given channel.

If a user’s JOIN command is successful, the server:

Sends them a JOIN message described above.
May send a MODE message with the current channel’s modes.
Sends them RPL_TOPIC and RPL_TOPICTIME numerics if the channel has a topic set (if the topic is not set, the user is sent no numerics).
Sends them one or more RPL_NAMREPLY numerics (which also contain the name of the user that’s joining).
The examples illustrate some full channel join bursts.

C  ->  JOIN #test
S <-   :dan!~d@0::1 JOIN #test
S <-   :irc.example.com MODE #test +nt
S <-   :irc.example.com 353 dan = #test :@dan
S <-   :irc.example.com 366 dan #test :End of /NAMES list.
*/

e_error	Command::_join	(void)
{
	if ((*this->_msgs_it).size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		if (check_chan_name((*this->_msgs_it)[1]) == false || check_chan_name(case_proof((*this->_msgs_it)[1])) == false)
			return (ERROR_CONTINUE);
		Channel::CHAN_USER_LIST *tmp = NULL;
		if ((_chans_it = this->_chans.find(case_proof((*this->_msgs_it)[1]))) == _chans.end())
		{
			this->_chans[case_proof((*this->_msgs_it)[1])] = new Channel((*this->_msgs_it)[1], "");
			_chans_it = this->_chans.find(case_proof((*this->_msgs_it)[1]));
			(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), 2);
			
		}
		tmp = &(*_chans_it).second->get_chan_user_list();
		(*tmp)[(*_users_it)->get_nickname()] = *_users_it;
		for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
			std::cout << (*it).second->get_nickname() << std::endl;
		return (this->_cmd_join());
	}
	return (SUCCESS);
}
