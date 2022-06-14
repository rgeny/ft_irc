/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:56:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/14 11:13:01 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"


e_error	Message::_cmd_mode	(int broadcast, String mode_change) const
{
	String	msg;
	String 	args_list;
	for (size_t i = 3; i < _cmd.size(); i++)
	{
		if (i > 3)
			args_list += " ";
		if (i == _cmd.size() - 1)
			args_list += ":";
		args_list += _cmd[i];
	}
	std::cout << "args_list: " << args_list << std::endl;
	String  final_part = mode_change + " " + args_list;
	Channel *cur_chan = (*this->_chans_it).second;
	User* cur_user = (*this->_users_it);
	String nickname = cur_user->get_nickname();
	String username = cur_user->get_username();
		
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