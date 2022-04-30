/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chanoprivsneeded.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:21:59 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/30 21:26:02 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_chanoprivsneeded	(void) const
{
	String	msg	= this->_set_reply_base(ERR_CHANOPRIVSNEEDED) + (*_chans_it).second->get_chan_name() +
				+ " :You do not have access to change the topic on this channel\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
