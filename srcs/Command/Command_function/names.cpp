/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:17:17 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/07 11:04:21 by abesombes        ###   ########.fr       */
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
            if (cur_chan && user_exist_in_chan(*cur_chan, (*_users_it)->get_nickname()) == false)
                name_list = cur_chan->get_name_list(0);
            else if (cur_chan)
                name_list = cur_chan->get_name_list(1);
            if (!name_list.empty())
                _rpl_namreply(name_list);
            _rpl_endofnames();
        }
    }
	return (SUCCESS);
}