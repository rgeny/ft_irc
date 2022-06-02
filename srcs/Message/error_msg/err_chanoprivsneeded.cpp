/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chanoprivsneeded.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:21:59 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/01 19:55:45 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_chanoprivsneeded	(String reason) const
{
	Channel *cur_chan = (*this->_chans_it).second;
	String	msg	= this->_set_reply_base(ERR_CHANOPRIVSNEEDED) 
				+ cur_chan->get_chan_name()
				+ " :"
				+ reason
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
