/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_endofwho.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:05 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/08 18:52:13 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_endofwho	(String target) const
{
	String msg	= this->_set_reply_base(RPL_ENDOFWHO)
				+ target
				+ " :End of /WHO list."
				+ "\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}