/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:49:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 10:13:25 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_error	(e_error code)
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
	this->_tmp_users[&cur_user] = 0;
	return (code);
}
