/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:53:29 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/08 18:03:46 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "Utils.hpp"

/*

14:14:47 <-- chat.freenode.org | WHO #ufeff

│14:14:47 --> chat.freenode.org | :*.freenode.net 352 abesombes #ufeff ~yuitimoth freenode-0p2.4rb.4geju9.IP *.freenode.net yuitimothy Hs :0 Chief Entropy Officer
│14:14:47 --> chat.freenode.org | :*.freenode.net 352 abesombes #ufeff ~morg freenode-0lr.u31.uqf24m.IP *.freenode.net Morgawr H@s :0 morg
│14:14:47 --> chat.freenode.org | :*.freenode.net 352 abesombes #ufeff ~abesombes freenode-20tu5s.5v3d.41bj.c5chqd.IP *.freenode.net abesombes H :0 abesombes
│14:14:47 --> chat.freenode.org | :*.freenode.net 352 abesombes #ufeff ~abesombes freenode-g1c.hr3.v5gmsu.IP *.freenode.net Krilin Hs :0 Alexandre BESOMBES
│14:14:47 --> chat.freenode.org | :*.freenode.net 315 abesombes #ufeff :End of /WHO list.

*/

e_error	Command::_who	(void)
{
    std::vector<User*> nick_list;
    String who_list;
    User* target_user = NULL;
    Channel *cur_chan = NULL;

    if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
        if (has_begin_hashtag(_cmd[1]) && _chans.find(_cmd[1]) != _chans.end())
        {
            _chans_it = _chans.find(_cmd[1]);
            cur_chan = (*this->_chans_it).second;
            if (user_exist_in_chan(*cur_chan, (*_users_it)->get_nickname()) == false)
                nick_list = cur_chan->get_raw_nick_list(CHAN_USER_STATUS);
            else
                nick_list = cur_chan->get_raw_nick_list(CHAN_OP_STATUS);
            if (nick_list.size() > 0)
            {
                for (std::vector<User*>::iterator it = nick_list.begin(), ite = nick_list.end(); it != ite; it++)
                {
                    who_list = (*it)->get_user_moredetail(_hostname, _cmd[1]);
                    _rpl_whoreply(who_list);
                }
            }
        }
        else if (!has_begin_hashtag(_cmd[1]) && (target_user == _get_user(_cmd[1])))
        {
            who_list = target_user->get_user_moredetail(_hostname, _cmd[1]);
            if (!who_list.empty())
                _rpl_whoreply(who_list);
        }
        // if (this->_chan_exist((*this->_chans_it).first) == true)
            _rpl_endofwho();
    }
	return (SUCCESS);
}