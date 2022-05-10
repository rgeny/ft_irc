/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_luserop.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:34:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 19:37:57 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_luserop	(void) const
{
	size_t	n_ope	= this->_count_operator();
	if (n_ope == 0)
		return (SUCCESS);
	std::stringstream	ss_n_ope;
	ss_n_ope	<< n_ope;
	String	msg	= this->_set_reply_base(RPL_LUSEROP)
				+ ss_n_ope.str()
				+ " :operator(s) online.\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
