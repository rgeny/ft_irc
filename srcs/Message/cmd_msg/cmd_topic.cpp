/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_topic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:23:29 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/08 11:51:04 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_topic	(int choice) const
{
	Channel *cur_chan = (*this->_chans_it).second;
	String nickname = (*this->_users_it)->get_nickname();
	String username = (*this->_users_it)->get_username();
    String topic = cur_chan->get_topic();
	std::cout << "current topic: " << topic << std::endl;
	User *cur_user = (*this->_users_it);
	*_chan_user_list = cur_chan->get_chan_user_list();
	if (topic.empty())
		topic = ":";
	else
		topic = ":" + topic;
	if (choice == 1)
	{
		String	msg	= this->_set_msg_base(nickname
										+ "!" 
										+ username
										+ "@"
										+ this->_hostname
										, String(TOPIC) 
										+ " " 
										+ this->_cmd[1]
										, topic)
										+ "\r\n";
		cur_user->add_to_queue(msg);
		for (Channel::CHAN_USER_LIST::iterator it = _chan_user_list->begin(), ite = _chan_user_list->end(); it != ite; it++)
		{
			if ((*it).second != *_users_it)
			{
				String	msg	= this->_set_msg_base(nickname
											+ "!" 
											+ username
											+ "@"
											+ this->_hostname 
											, String(TOPIC)
											+ " " 
											+ this->_cmd[1]
											, topic)
											+ "\r\n";
				(*it).second->add_to_queue(msg);
			}
		}
	}
	else if (choice == 2)
	{
		String	msg;
		if (topic.empty())
		{
			_rpl_notopic();
		}
		else
		{
			_rpl_topic();
			_rpl_topicwhotime();
		}
		cur_user->add_to_queue(msg);
		return (SUCCESS);
	}
	return (SUCCESS);
}