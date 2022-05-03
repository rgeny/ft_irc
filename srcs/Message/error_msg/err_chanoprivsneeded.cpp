/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chanoprivsneeded.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:21:59 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/03 17:03:06 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_chanoprivsneeded	(void) const
{
	String	msg	= this->_set_reply_base(ERR_CHANOPRIVSNEEDED) 
				+ (*_chans_it).second->get_chan_name()
				+ " :You must be a channel operator\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
