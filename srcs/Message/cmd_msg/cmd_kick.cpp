/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_kick.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:21:42 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/03 16:42:06 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include "Channel.hpp"

/*

S <-   :alice!a@localhost JOIN :#Melbourne
C  ->  KICK #Melbourne alice
S <-   :dan!d@localhost KICK #Melbourne alice :dan
dan kicking a user with no reason given

C  ->  JOIN #test
S <-   :alice!a@localhost JOIN :#test
S <-   :irc.example.com 353 alice = #test :alice @dan
S <-   :irc.example.com 366 alice #test :End of /NAMES list.
S <-   :dan!d@localhost KICK #test alice :dan
alice getting kicked with no reason given

S <-   :alice!a@localhost JOIN :#test
C  ->  kick #test alice :nah mate
S <-   :dan!d@localhost KICK #test alice :nah mate
dan kicking a user with a reason

C  ->  join #test
S <-   :alice!a@localhost JOIN :#test
S <-   :irc.example.com 353 alice = #test :alice @dan
S <-   :irc.example.com 366 alice #test :End of /NAMES list.
S <-   :dan!d@localhost KICK #test alice :nah mate
alice getting kicked with a reason given

C  ->  JOIN #test
S <-   :alice!a@localhost JOIN :#test
S <-   :irc.example.com 353 alice = #test :alice @dan
S <-   :irc.example.com 366 alice #test :End of /NAMES list.
C  ->  KICK #test dan
S <-   :irc.example.com 482 alice #test :You're not channel operator
alice kicking with no permissions

C  ->  JOIN #v3
S <-   :dan!d@Clk-830D7DDC JOIN :#v3
S <-   :irc.example.com 353 dan = #v3 :@dan
S <-   :irc.example.com 366 dan #v3 :End of /NAMES list.
C  ->  KICK #v3 tom
S <-   :irc.example.com 401 dan tom :No such nick/channel
C  ->  KICK #v3 jerry
S <-   :irc.example.com 441 dan jerry #v3 :They aren't on that channel
dan kicking a user that does not exist, and a user that isn’t on the channel

*/

e_error	Message::_cmd_kick	(String reason) const
{
    (void)reason;
    	return (SUCCESS);
}