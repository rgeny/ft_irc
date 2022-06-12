/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quit.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:55:05 by abesombes         #+#    #+#             */
/*   Updated: 2022/06/12 19:48:10 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

/* 
abesombes1!~abesombes@freenode-9sn3bd.5v3d.41bj.c5chqd.IP QUIT :Quit: WeeChat 2.8
*/

e_error	Message::_cmd_quit (void) const
{
    String	msg;
	User* cur_user = (*this->_users_it);
	String nickname = cur_user->get_nickname();
    String username = cur_user->get_username();
		
	msg	= this->_set_msg_base(nickname
							+ "!" 
							+ username
							+ "@"
							+ this->_hostname
							, String(QUIT)
							+ " " 
							+ ":Quit"
							,": Leaving IRC Majinboo Server")
							+ "\r\n";
    _broadcast_to_chan_members(msg);

	return (SUCCESS);
}