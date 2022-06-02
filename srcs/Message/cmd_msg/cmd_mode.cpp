/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:56:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/02 16:09:24 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"


e_error	Message::_cmd_mode	(int broadcast) const
{
	String	msg;
	String  part1 = (_cmd.size() > 3 ? _cmd[2] + "" : ":" + _cmd[2]);
	String 	part2 = (_cmd.size() > 3 ? " :" + _cmd[3] : "");
	String  final_part = part1 + part2;
	Channel *cur_chan = (*this->_chans_it).second;
	User* cur_user = (*this->_users_it);
	String nickname = cur_user->get_nickname();
	String username = cur_user->get_nickname();
		
	msg	= this->_set_msg_base(nickname
							+ "!" 
							+ username
							+ "@"
							+ this->_hostname
							, this->_cmd[0] 
							+ " " 
							+ this->_cmd[1]
							, final_part )
							+ "\r\n";

	cur_user->add_to_queue(msg);
	if (broadcast == 1)
	{
		Channel::CHAN_USER_LIST chan_ulist = cur_chan->get_chan_user_list();
		for (Channel::CHAN_USER_LIST::iterator it = chan_ulist.begin(), ite = chan_ulist.end(); it != ite; it++)
		{
			if ((*_users_it) != it->second)
				(*it).second->add_to_queue(msg);
		}
	}
	return (SUCCESS);
}