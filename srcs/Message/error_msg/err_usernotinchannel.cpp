/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_usernotinchannel.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:17:52 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/11 19:06:10 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Message.hpp"

e_error	Message::_err_usernotinchannel	(String nickname, String chan_name) const
{
	String	msg	= this->_set_reply_base (ERR_USERNOTINCHANNEL)
				+ nickname
				+ " "
				+ chan_name
				+ " :They are not on that channel\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}