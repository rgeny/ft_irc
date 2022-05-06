/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_list.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:53:59 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 20:34:44 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_list	(std::vector<String> list) const
{
    // User &	cur_user	= *(*this->_users_it);
	for (std::vector<String>::iterator it = list.begin(), ite = list.end(); it != ite; it++)
	{
        String	msg	= this->_set_reply_base(RPL_LIST)
                + *it
				+ "\r\n";

	    (*_users_it)->add_to_queue(msg);
    }
    return (SUCCESS);
}