/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_banlist.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:08 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/16 22:10:35 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_banlist	(void) const
{
    String	msg;
    Channel *cur_chan = (*this->_chans_it).second;
    Channel::CHAN_BAN_LIST chan_blist = cur_chan->get_chan_ban_list();
    time_t creation_time;

    std::vector<Channel::CHAN_BAN_LIST::iterator> sorted_list_of_bans;

    Channel::CHAN_BAN_LIST::iterator    ite = chan_blist.end();
    Channel::CHAN_BAN_LIST::iterator    last_min = ite;
    for (size_t i = 0; i < chan_blist.size(); i++)
    {
        Channel::CHAN_BAN_LIST::iterator    min = ite;
        for (Channel::CHAN_BAN_LIST::iterator it = chan_blist.begin(); it != ite; it++)
        {
            if (last_min == ite)
            {
                if (min == ite)
                    min = it;
                else if ((*min).second.second > (*it).second.second)
                    min = it;
            }
            else
            {
                if (min == ite && (*last_min).second.second < (*it).second.second)
                    min = it;
                else if ((*min).second.second > (*it).second.second && (*last_min).second.second < (*it).second.second)
                    min = it;
            }
        }
            sorted_list_of_bans.push_back(min);
            last_min = min;

    }

    for (std::vector<Channel::CHAN_BAN_LIST::iterator>::iterator it = sorted_list_of_bans.begin(), ite = sorted_list_of_bans.end(); it != ite; it++)
    {
        creation_time = ((*(*it)).second).second;
        std::stringstream    tmp;
        tmp << creation_time;
        String    ban_creation_time(tmp.str());
        String    ban_creator = (*(*it)).second.first->get_nickname();
        String    ban_mask = (*(*it)).first;
        std::cout << "Ban Creation Time: " << creation_time << " - creator: " << ban_creator << " - ban_mask: " << ban_mask << std::endl;
        msg	= this->_set_reply_base(RPL_BANLIST)
            + (*_chans_it).second->get_chan_name()
            + " "
            + ban_mask + "!*@*"
            + " "
            + ban_creator
            + " :"
            + ban_creation_time
            + "\r\n";
        (*this->_users_it)->add_to_queue(msg);
    }

	return (SUCCESS);
}
