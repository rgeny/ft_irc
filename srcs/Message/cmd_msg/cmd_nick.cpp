/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:02:32 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/12 19:50:37 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "User.hpp"

e_error	Message::_cmd_nick	(String & oldest) const
{
	String nickname = (*this->_users_it)->get_nickname();
	std::map<String, String> mailing_list;
	if (oldest == DFL_NICKNAME)
		return (ERROR_CONTINUE);
	String	msg	= this->_set_sender(oldest)
				+ " "
				+ NICK
				+ " :"
				+ nickname
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	mailing_list[nickname] = nickname;
	mailing_list[oldest] = oldest;
	_broadcast_to_chan_members(msg);
	
	return (SUCCESS);
}
