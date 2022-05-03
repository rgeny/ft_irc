/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:44:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/03 13:51:35 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

/*
 Command: PRIVMSG
  Parameters: <target>{,<target>} <text to be sent>
The PRIVMSG command is used to send private messages between users, as well as to send messages to channels. <target> is the nickname of a client or the name of a channel.
*/

e_error	Command::_privmsg	(void)
{
    if (this->_cmd.size() < 3)
		return (this->_err_needmoreparams());
	else
	{
        String msg = concat_last_args(2);
        return (this->_cmd_privmsg(msg));
    }
    return (SUCCESS);
}
