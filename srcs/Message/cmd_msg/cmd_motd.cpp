/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_motd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:03:00 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/02 10:57:25 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

static const char *motd[] = {
"",
"Hello, World!",
"",
"",
"Welcome to MajinBooIRC",
"",
"          (｡◝‿◜｡)       ",
"",
"Type /join #<channel>",
"",
"",
"Thank you for using MajinBooIRC!",
"",
NULL };


e_error	Message::_cmd_motd	(void) const
{
    String  msg;
    msg	= this->_set_msg_base(this->_hostname, "375 "
                            + (*this->_users_it)->get_nickname()
                            + " "
                            , ""
                            , this->_hostname + " Message of the Day")
                            + "\r\n";
    (*this->_users_it)->add_to_queue(msg);
    for (size_t i = 0; ::motd[i]; ++i)
    {
        msg	= this->_set_msg_base(this->_hostname, "372 "
                                    + (*this->_users_it)->get_nickname()
                                    + " "
                                    , ""
                                    , ::motd[i])
                                    + "\r\n";
        (*this->_users_it)->add_to_queue(msg);
    }
    msg	= this->_set_msg_base(this->_hostname, "376 "
                            + (*this->_users_it)->get_nickname()
                            + " "
                            , ""
                            , ":End of /MOTD command.")
                            + "\r\n";
    (*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
