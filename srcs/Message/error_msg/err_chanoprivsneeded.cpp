/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chanoprivsneeded.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:21:59 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/05 11:25:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_chanoprivsneeded	(String reason) const
{
	String	msg	= this->_set_reply_base(ERR_CHANOPRIVSNEEDED) 
				+ (*_chans_it).second->get_chan_name()
				+ " :"
				+ reason
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
