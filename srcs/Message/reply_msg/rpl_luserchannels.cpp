/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_luserchannels.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:47:16 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 19:55:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_luserchannels	(void) const
{
	size_t	n_chans	= this->_chans.size();

	if (n_chans == 0)
		return (SUCCESS);
	std::stringstream	ss_n_chans;
	ss_n_chans	<< n_chans;

	String	msg	= this->_set_reply_base(RPL_LUSERCHANNELS)
				+ ss_n_chans.str()
				+ " :channels formed.\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
