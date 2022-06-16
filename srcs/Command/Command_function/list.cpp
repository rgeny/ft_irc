/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:05:19 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/15 23:11:41 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "Utils.hpp"

String Command::generate_channel_mode(Channel* cur_chan)
{
	return ("[+"
			+ String((cur_chan->get_specific_mode(CHANMODE_i) ? "i": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_t) ? "t": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_n) ? "n": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_m) ? "m": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_l) ? "l": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_b) ? "b": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_k) ? "k": ""))
			+ "]");
}

void Command::add_to_list(Channel* cur_chan, std::vector<String>* list)
{
	int nb_users;
	String channel_mode;
	String nb_users_str;
	String topic = cur_chan->get_topic();
	if (!cur_chan->get_specific_mode(CHANMODE_p) && !cur_chan->get_specific_mode(CHANMODE_s))
	{
		nb_users = cur_chan->get_chan_user_list().size();
		channel_mode = generate_channel_mode(cur_chan);
		std::stringstream ss;  
		ss << nb_users;  
		ss >> nb_users_str; 
		list->push_back(cur_chan->get_chan_name() + " " + nb_users_str + " " + channel_mode + (topic.empty()? "" : " " + topic));
	}
}

e_error	Command::_list	(void)
{
	std::vector<String>	list;
	Channel * cur_chan = NULL;

	if (_cmd.size() < 2)
	{
		for (CHANS_IT it = _chans.begin(), ite = _chans.end(); it != ite; it++)
		{
			cur_chan = ((*it).second);
			add_to_list(cur_chan, &list);
		}
	}
	else
	{
		_chan_list = split(this->_cmd[1], ",");
		for (std::vector<String>::iterator it = _chan_list.begin(), ite = _chan_list.end(); it != ite; it++)
		{
			cur_chan = (*(_chans.find(*it))).second;
			String cur_chan_name = *it;
			if (this->_chan_exist(cur_chan_name) == false)
			{
				_err_nosuchchannel(cur_chan_name);
				continue;
			}
			add_to_list(cur_chan, &list);
		}
	}

	_rpl_list(list);
	_rpl_listend();
	return (SUCCESS);
}
