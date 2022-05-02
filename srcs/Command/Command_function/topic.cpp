/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:08:30 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/02 16:01:37 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_topic	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
		std::cout << "I am in TOPIC\n";
		if (!has_begin_hashtag(this->_cmd[1]))
		{
			return (this->_err_nosuchchannel());
		}
		else 
		{
			if (chan_exist(_cmd[1]) == false)
				return (this->_err_nosuchchannel());
			else
			{
				this->_chans_it = (this->_chans.find(_cmd[1]));
				if (this->_cmd.size() > 2)
				{
					if (user_exist_in_chan(*(*this->_chans_it).second, (*_users_it)->get_nickname()) == false)
						return (_err_notonchannel());
					String tmp;
					for (std::vector<String>::iterator it = _cmd.begin() + 2, ite = _cmd.end(); it != ite; it++)
					{
						if (it != _cmd.begin() + 2)
							tmp = tmp + " ";
						tmp = tmp + *it;
					}
					std::cout << "TMP: " << tmp << std::endl;
					if (is_operator((*_users_it)->get_nickname(), *(*this->_chans_it).second))
						(*this->_chans_it).second->set_topic(tmp);
					else
						return (_err_chanoprivsneeded());
				}
				else if (this->_cmd.size() == 2)
				{
					return (this->_cmd_topic(2));
				}
			}
		}
		return (this->_cmd_topic(1));
	}
	return (SUCCESS);
}