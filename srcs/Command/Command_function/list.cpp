/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:05:19 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 20:38:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "Utils.hpp"

e_error	Command::_list	(void)
{
	std::vector<String>	list;
	int nb_users;

	for (CHANS_IT it = _chans.begin(), ite = _chans.end(); it != ite; it++)
	{
		Channel * cur_chan = ((*it).second);
		String channel_mode;
		String nb_users_str;
		if (!cur_chan->get_specific_mode(CHANMODE_p) && !cur_chan->get_specific_mode(CHANMODE_s))
		{
			nb_users = cur_chan->get_chan_user_list().size();
			channel_mode = "[+"
			+ String((cur_chan->get_specific_mode(CHANMODE_i) ? "i": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_t) ? "t": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_n) ? "n": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_m) ? "m": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_l) ? "l": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_b) ? "b": ""))
			+ String((cur_chan->get_specific_mode(CHANMODE_k) ? "k": ""))
			+ "]";
			std::stringstream ss;  
			ss << nb_users;  
			ss >> nb_users_str; 
			list.push_back(cur_chan->get_chan_name() + " " + nb_users_str + " " + channel_mode);
		}
	}

	_rpl_list(list);
	_rpl_listend();
	return (SUCCESS);
}
