/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:17:17 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/31 21:48:40 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "Utils.hpp"

e_error	Command::_names	(void)
{
    std::vector<String> chan_list;
    String name_list;
    Channel *cur_chan = NULL;

    chan_list = split(this->_cmd[1], ",");

    for (std::vector<String>::iterator it = chan_list.begin(), ite = chan_list.end(); it != ite; it++)
    {
        _cmd[1] = *it;
        if (_chans.find(*it) != _chans.end())
        {
            _chans_it = _chans.find(*it);
            cur_chan = (*this->_chans_it).second;
            if (check_chan_name(*it) == false || check_chan_name(*it) == false)
                return (_err_badchanmask());
            if (user_exist_in_chan(*cur_chan, (*_users_it)->get_nickname()) == false)
                name_list = cur_chan->get_name_list(0);
            else
                name_list = cur_chan->get_name_list(1);
            if (!name_list.empty())
                _rpl_namreply(name_list);
            _rpl_endofnames();
        }
    }
	return (SUCCESS);
}