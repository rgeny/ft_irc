/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_welcome.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:37:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:35:19 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_welcome	(void) const
{
	User &	cur_user	= *(*this->_users_it);
	String	msg	= this->_set_reply_base(RPL_WELCOME)
				+ "Welcome to the Internet Relay Network "
				+ cur_user.get_nickname()
				+ "!"
				+ cur_user.get_username()
				+ "@"
				+ this->_servername
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
