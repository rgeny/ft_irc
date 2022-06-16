/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_info.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:03:00 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/16 10:05:54 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

static const char *info[] = {
"",
"42 Project : ft_irc => ircserv",
"",
"Based on RFC 2812",
"",
"This program is free software: you can redistribute it and/or modify",
"it under the terms of the GNU General Public License as published by",
"the Free Software Foundation, either version 3 of the License, or",
"(at your option) any later version.",
"",

"                                   ⢀⡠⠒⠉⠉⢲⡄                          ",
"               ⠀⠀⠀⡠⠔⠒⠐⣦     ⠀⠀⠀⢠⠎⠀⠀⠀⡞⣹⡇                          ",
"               ⠀⠀⢾⠦⠠⢴⣋⢉⡇⠀⠀⠀⡠⠖⠊⠉⠀⠀⠀⠰⠓⢯⡀                          ",
"               ⠀⠀⢰     ⣶⢀⣠⣤⠊          ⠑⠐⠘⡄                         ",
"               ⠀⠀⢸⠒⠒⠂⢤⠿⡮⠃⠀⠀⠀⢀⡀⣔⡄⢀⡀     ⣾                         ",
"               ⠀⠀⠈⠆⠀⠀⠘⣄⡱⠃⠀⠛⠛⠛⠿⡉⠀⠈⢽⣶⣄⡀⠀⠛⡒⡄                       ",
"               ⠀⠀⠀⢎⠀⠀⠀⠙⢱     ⠀⠀⡏⠑⡸⠀⠉⠉⠉⠀⢀⢃⠇⢀⡀                     ",
"               ⠀⠀⢀⡨⢦⠀⢰⢸⡞⣦⡀     ⢡⡔⠁     ⠀⢈⡇⡞⠁⠈⠓⡄                  ",
"               ⡠⠔⠉⠀⡼⠯⠽⣛⡑⣝⠛⠦⣄⡀⠀⠈     ⠀⢀⣠⣾⢳⠁⠀⠀⠸⠏⢢⡀                ",
"          ⠀⣠⠔⠋     ⣿⣦⡈⠉⠁⢸⡏⢑⡾⢿⡟⢶⣶⣶⣶⣶⠟⢛⡯⣷⠋⠛⢶⠞⠂⠀⣀⡟                ",
"     ⠀⠀⠀⡠⠞⠁     ⠀⣠⢇⠈⠻⢷⣶⢷⣔⣁⣎⠝⠚⢟⠢⡈⢻⣩⢿⠫⠶⢻⣶⣀⠈⢶⡒⠋⠁⡚               ",
"     ⠀⡠⠊     ⠀⡠⠚⠉⢈⣪⡓⢤⡀⠀⠈⠁     ⠀⠑⢤⡀⣧⣣⣀⣀⣀⣈⣿⡗⠒⡖⢖⠊                 ",
"⠀⠀⠀⢠⠎     ⠀⠀⢸⠁⢠⠐⡱⠊⠙⠢⡈⠑⠢⣄     ⠀⠀⠀⠈⠃⠉⠙⠛⠋⠉⣻⡇⠀⠘⣎⠣⡀               ",
"⠀⠀⠀⡮⠴⠒⠓⠲⣄⠀⠀⢸⠀⠘⠀⠁⠀⠀⠀⡨⠦⡞⢁⢹⣖⠲⣂⠤⢤⠤⠤⠤⠤⠰⣖⣒⠭⢾⡉⢢⠀⠈⢆⠙⢄              ",
"          ⠘⢆⠀⠐⢆⢰⠀⠸⠀⠀⠰⢁⡔⠙⢿⣛⡹⠏⣯⣄⣠⣤⠤⠒⡍⢏     ⢳⠀⡇⠀⠈⢇⠀⢳              ",
"          ⠀⠈⠣⡀⠀⢙⣦⣇⠀⠀⠀⠈⠀⠀⠀⠈⠈⠉⠉⠀⢡⠈⡄⠀⢘⠈     ⣸⠀⡇⠀⠀⢹⠀⠈⡇            ",
"          ⠀⠀⠀⠈⡻⢻⡀⠈⢲⣄⡀⡇          ⠘     ⠀⠀⡼⠀⠀⣏⡰⠁⣀⠔⣺⠀⠠⡇            ",
"          ⠀⠀⠀⡠⢣⡀⠉⢉⡩⠇⠈⠡⣄⣀⠀⠀⠀⢮⡦⡀⠀⠀⢀⠀⠀⡠⢂⠇⣠⠞⠛⠒⠊⠁⢀⠏⣠⠞              ",
"          ⠀⠀⣜⣀⣀⣈⣠⠎     ⠀⠀⠉⠒⠒⠒⠛⠚⠒⠒⠓⢲⠚⠳⠭⢭⠇     ⠰⠟⠊⠁              ",
"          ⠀⠀⠈⠉⠁                    ⠀⠀⣎⠓⠒⠒⠊⠒⢄                        ",
"                                        ⠉⠉⠑⠒⠒⠚                       ",
"Authors: (｡◝‿◜｡)",
"- Vanessa ZAPATA       - ayzapata",
"- Remy GENY            - rgeny",
"- Alexandre BESOMBES   - abesombe",
"42 students",
"2022",
"",
NULL };


                    
e_error	Message::_cmd_info	(void) const
{
    String nickname = (*this->_users_it)->get_nickname();
    for (size_t i = 0; ::info[i]; ++i)
    {
        String  msg	= this->_set_msg_base(this->_servername, "371 "
                                        + nickname
                                        + ""
                                        , ""
                                        , ::info[i])
                                        + "\r\n";
        (*this->_users_it)->add_to_queue(msg);
    }
    String  msg	= this->_set_msg_base(this->_servername, "374 "
                                    + nickname
                                    + ""
                                    , ""
                                    , ":End of /INFO list.")
                                    + "\r\n";
    (*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
