/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:08:30 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/20 16:48:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_topic	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams(_cmd[0]));
	else
	{
		if (!has_begin_hashtag(this->_cmd[1]))
		{
			return (this->_err_nosuchchannel(_cmd[1]));
		}
		else 
		{
			if (this->_chan_exist(_cmd[1]) == false)
				return (this->_err_nosuchchannel(_cmd[1]));
			else
			{
				this->_chans_it = (this->_chans.find(_cmd[1]));
				Channel *cur_chan = (*this->_chans_it).second;
				String cur_chan_name = cur_chan->get_chan_name();
				String cur_nickname = (*_users_it)->get_nickname();
				if (this->_cmd.size() > 2)
				{
					if (user_exist_in_chan(*cur_chan, cur_nickname) == false)
						return (_err_notonchannel());
					String tmp;
					for (std::vector<String>::iterator it = _cmd.begin() + 2, ite = _cmd.end(); it != ite; it++)
					{
						if (it != _cmd.begin() + 2)
							tmp = tmp + " ";
						tmp = tmp + *it;
					}
					std::cout << "tmp: " << tmp << std::endl;
					bool is_topic_blocked = cur_chan->get_specific_mode(CHANMODE_t);
					if (is_operator((*_users_it)->get_nickname(), *cur_chan) || (is_topic_blocked == false))
					{
						cur_chan->set_topic(tmp);
						cur_chan->set_topic_creation_time(time(0));
						cur_chan->set_topic_creator(*_users_it);
					}
					else
						return (_err_chanoprivsneeded());
				}
				else if (this->_cmd.size() == 2)
				{
					if (user_exist_in_chan(*cur_chan, (*_users_it)->get_nickname()) == false)
						return (_err_notonchannel());
						
					bool is_secret_chan = cur_chan->get_specific_mode(CHANMODE_s);
					if (cur_chan->get_topic().empty())
						return (this->_rpl_notopic());
					else if (!is_secret_chan)
						return (this->_cmd_topic(2));
					else
						return (_err_nosuchchannel(cur_chan->get_chan_name()));
				}
			}
		}
		return (this->_cmd_topic(1));
	}
	return (SUCCESS);
}
