/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:49:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:31:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_error	(e_error code) const
{
	User &	cur_user	= *(*this->_users_it);
	String	msg	= String(ERROR)
				+ " :Closing link: "
				+ cur_user.get_nickname()
				+ " by "
				+ this->_servername
				+ " ";
	MsgError_it	it = this->_msg_error.find(code);
	if (it == this->_msg_error.end())
		return (code);
	msg += (*it).second;
	cur_user.add_to_queue(msg);
	cur_user.be_disconnected = true;
	return (code);
}
