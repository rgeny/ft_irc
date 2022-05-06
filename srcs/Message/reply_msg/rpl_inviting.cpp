/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_inviting.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:41:44 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 10:48:01 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Message.hpp"

e_error	Message::_rpl_inviting	(void) const
{
	User &	cur_user	= *(*this->_users_it);
	String	msg	= this->_set_reply_base(RPL_INVITING)
				+ _cmd[1]
				+ " "
				+ _cmd[2]
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
