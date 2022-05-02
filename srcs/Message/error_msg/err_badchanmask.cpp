/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_badchanmask.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:22:17 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/02 18:54:26 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_badchanmask	(void) const
{
	String	msg	= this->_set_reply_base (ERR_BADCHANMASK)
				+ "0 :Invalid channel name\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
