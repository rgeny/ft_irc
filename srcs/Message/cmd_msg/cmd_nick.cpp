/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:02:32 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/10 11:02:43 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "User.hpp"

e_error	Message::_cmd_nick	(String & oldest) const
{
	String nickname = (*this->_users_it)->get_nickname();
	std::map<String, String> mailing_list;
	if (oldest == DFL_NICKNAME)
		return (ERROR_CONTINUE);
	String	msg	= this->_set_sender(oldest)
				+ " "
				+ NICK
				+ " :"
				+ nickname
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	mailing_list[nickname] = nickname;
	mailing_list[oldest] = oldest;
	User::CHAN_USERMODE chan_usermode = (*this->_users_it)->get_chan_usermode();

	for (User::CHAN_USERMODE::iterator it = chan_usermode.begin(), ite = chan_usermode.end(); it != ite; it++)
	{
		Channel *current_chan = (*(_chans.find((*it).first))).second;
		std::cout << "current_chan: " << current_chan->get_chan_name() << std::endl;
		for (Channel::CHAN_USER_LIST::iterator itu = current_chan->get_chan_user_list().begin(), itue = current_chan->get_chan_user_list().end(); itu != itue; itu++)
		{
			std::cout << "itu->first = " << itu->first << " vs nickname = " << nickname << std::endl;
			String cur_target = itu->first;
			if (cur_target != nickname && mailing_list.find(cur_target) == mailing_list.end())
			{
				itu->second->add_to_queue(msg);
				mailing_list[cur_target] = cur_target;
			}
		}
	}
	
	return (SUCCESS);
}
