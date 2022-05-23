/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whois.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:24:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/23 19:05:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include "Utils.hpp"

/*

│16:13:27 <-- chat.freenode.org | WHOIS Morgawr
│16:13:27 --> chat.freenode.org | :*.freenode.net 311 abesombes Morgawr ~morg freenode-0lr.u31.uqf24m.IP * :morg
│16:13:27 --> chat.freenode.org | :*.freenode.net 319 abesombes Morgawr :@#ufeff #vidyadev
│16:13:27 --> chat.freenode.org | :*.freenode.net 312 abesombes Morgawr *.freenode.net :freenode
│16:13:27 --> chat.freenode.org | :*.freenode.net 318 abesombes Morgawr :End of /WHOIS list.

*/

e_error	Command::_whois	(void)
{
    String user_details;
    String user_chan_list;
    User* target_user = NULL;

    if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
        target_user = _get_user(_cmd[1]);
        if (!has_begin_hashtag(_cmd[1]) && target_user != NULL)
        {
            user_details = target_user->get_user_details();
            user_chan_list = target_user->get_user_chan_list();
            _rpl_whoisuser(user_details);
            if (!user_chan_list.empty())
                _rpl_whoischannels(user_chan_list);
            _rpl_whoisserver();
        }
        _rpl_endofwhois();
    }
	return (SUCCESS);
}