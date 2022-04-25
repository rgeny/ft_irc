/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:49:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 21:14:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_cmd_error	(e_error code) const
{
	User &	cur_user	= *(*this->_users_it);
	std::string	msg	= std::string(ERROR)
					+ " :Closing link: "
					+ cur_user.get_nickname()
					+ " by "
					+ this->_servername
					+ " ";
	switch (code)
	{
		case ERROR_BAD_PASSWD :
			msg += "(Bad Password)\r\n";
			break;
		default :
			return (code);
	}
	cur_user.add_to_queue(msg);
	cur_user.be_disconnected = true;
	return (code);
}
