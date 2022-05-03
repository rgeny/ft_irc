/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_usernotinchannel.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:17:52 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/03 17:20:29 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Message.hpp"

e_error	Message::_err_usernotinchannel	(void) const
{
	String	msg	= this->_set_reply_base (ERR_USERNOTINCHANNEL)
				+ this->_cmd[1]
				+ " :They are not on that channel\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
