/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nosuchchannel.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:15:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/15 23:15:52 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_nosuchchannel	(String chan_name) const
{
	String	msg	= this->_set_reply_base (ERR_NOSUCHCHANNEL)
				+ chan_name
				+ " :No such channel\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
