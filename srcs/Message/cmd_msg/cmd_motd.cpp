/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_motd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:03:00 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/02 15:56:59 by abesombe         ###   ########.fr       */
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
BOLD MAGENTA "__  __       _ _         ____       " RESET,               
BOLD MAGENTA "│  \\/  |     (_|_)       |  _ \\              " RESET,
BOLD MAGENTA "│ \\  / | __ _ _ _ _ __   | |_) | ___   ___    " RESET,
BOLD MAGENTA "│ |\\/| |/ _` | | | '_ \\  |  _ < / _ \\ / _ \\" RESET,  
BOLD MAGENTA "│ |  | | (_| | | | | | | | |_) | (_) | (_) |        (｡◝‿◜｡)" RESET,
BOLD MAGENTA "│_|  |_|\\__,_| |_|_| |_| |____/ \\___/ \\___/ " RESET, 
BOLD MAGENTA "            _/ |                               " RESET,
BOLD MAGENTA "            |__/                               " RESET,
BOLD MAGENTA "                                   ⢀⡠⠒⠉⠉⢲⡄                          " RESET,
BOLD MAGENTA "               ⠀⠀⠀⡠⠔⠒⠐⣦     ⠀⠀⠀⢠⠎⠀⠀⠀⡞⣹⡇                          " RESET,
BOLD MAGENTA "               ⠀⠀⢾⠦⠠⢴⣋⢉⡇⠀⠀⠀⡠⠖⠊⠉⠀⠀⠀⠰⠓⢯⡀                          " RESET,
BOLD MAGENTA "               ⠀⠀⢰     ⣶⢀⣠⣤⠊          ⠑⠐⠘⡄                         " RESET,
BOLD MAGENTA "               ⠀⠀⢸⠒⠒⠂⢤⠿⡮⠃⠀⠀⠀⢀⡀⣔⡄⢀⡀     ⣾                         " RESET,
BOLD MAGENTA "               ⠀⠀⠈⠆⠀⠀⠘⣄⡱⠃⠀⠛⠛⠛⠿⡉⠀⠈⢽⣶⣄⡀⠀⠛⡒⡄                       " RESET,
BOLD MAGENTA "               ⠀⠀⠀⢎⠀⠀⠀⠙⢱     ⠀⠀⡏⠑⡸⠀⠉⠉⠉⠀⢀⢃⠇⢀⡀                     " RESET,
BOLD MAGENTA "               ⠀⠀⢀⡨⢦⠀⢰⢸⡞⣦⡀     ⢡⡔⠁     ⠀⢈⡇⡞⠁⠈⠓⡄                  " RESET,
BOLD MAGENTA "               ⡠⠔⠉⠀⡼⠯⠽⣛⡑⣝⠛⠦⣄⡀⠀⠈     ⠀⢀⣠⣾⢳⠁⠀⠀⠸⠏⢢⡀                " RESET,
BOLD MAGENTA "          ⠀⣠⠔⠋     ⣿⣦⡈⠉⠁⢸⡏⢑⡾⢿⡟⢶⣶⣶⣶⣶⠟⢛⡯⣷⠋⠛⢶⠞⠂⠀⣀⡟                " RESET,
BOLD MAGENTA "     ⠀⠀⠀⡠⠞⠁     ⠀⣠⢇⠈⠻⢷⣶⢷⣔⣁⣎⠝⠚⢟⠢⡈⢻⣩⢿⠫⠶⢻⣶⣀⠈⢶⡒⠋⠁⡚               " RESET,
BOLD MAGENTA "     ⠀⡠⠊     ⠀⡠⠚⠉⢈⣪⡓⢤⡀⠀⠈⠁     ⠀⠑⢤⡀⣧⣣⣀⣀⣀⣈⣿⡗⠒⡖⢖⠊                 " RESET,
BOLD MAGENTA "⠀⠀⠀⢠⠎     ⠀⠀⢸⠁⢠⠐⡱⠊⠙⠢⡈⠑⠢⣄     ⠀⠀⠀⠈⠃⠉⠙⠛⠋⠉⣻⡇⠀⠘⣎⠣⡀               " RESET,
BOLD MAGENTA "⠀⠀⠀⡮⠴⠒⠓⠲⣄⠀⠀⢸⠀⠘⠀⠁⠀⠀⠀⡨⠦⡞⢁⢹⣖⠲⣂⠤⢤⠤⠤⠤⠤⠰⣖⣒⠭⢾⡉⢢⠀⠈⢆⠙⢄              " RESET,
BOLD MAGENTA "          ⠘⢆⠀⠐⢆⢰⠀⠸⠀⠀⠰⢁⡔⠙⢿⣛⡹⠏⣯⣄⣠⣤⠤⠒⡍⢏     ⢳⠀⡇⠀⠈⢇⠀⢳              " RESET,
BOLD MAGENTA "          ⠀⠈⠣⡀⠀⢙⣦⣇⠀⠀⠀⠈⠀⠀⠀⠈⠈⠉⠉⠀⢡⠈⡄⠀⢘⠈     ⣸⠀⡇⠀⠀⢹⠀⠈⡇            " RESET,
BOLD MAGENTA "          ⠀⠀⠀⠈⡻⢻⡀⠈⢲⣄⡀⡇          ⠘     ⠀⠀⡼⠀⠀⣏⡰⠁⣀⠔⣺⠀⠠⡇            " RESET,
BOLD MAGENTA "          ⠀⠀⠀⡠⢣⡀⠉⢉⡩⠇⠈⠡⣄⣀⠀⠀⠀⢮⡦⡀⠀⠀⢀⠀⠀⡠⢂⠇⣠⠞⠛⠒⠊⠁⢀⠏⣠⠞              " RESET,
BOLD MAGENTA "          ⠀⠀⣜⣀⣀⣈⣠⠎     ⠀⠀⠉⠒⠒⠒⠛⠚⠒⠒⠓⢲⠚⠳⠭⢭⠇     ⠰⠟⠊⠁              " RESET,
BOLD MAGENTA "          ⠀⠀⠈⠉⠁                    ⠀⠀⣎⠓⠒⠒⠊⠒⢄                        " RESET,
BOLD MAGENTA "                                        ⠉⠉⠑⠒⠒⠚                       " RESET,
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
    String nickname = (*this->_users_it)->get_nickname();
    msg	= this->_set_msg_base(this->_servername, "375 "
                            + nickname
                            + " "
                            , ""
                            , this->_servername 
                            + "Message of the Day")
                            + "\r\n";
    (*this->_users_it)->add_to_queue(msg);
    for (size_t i = 0; ::motd[i]; ++i)
    {
        msg	= this->_set_msg_base(this->_servername, "372 "
                                    + nickname
                                    + " "
                                    , ""
                                    , ::motd[i])
                                    + "\r\n";
		msg	= this->_set_msg_base(RPL_MOTD)
			+ nickname
			+ " "
			+ ::motd[i]
			+ "\r\n";
        (*this->_users_it)->add_to_queue(msg);
    }
    msg	= this->_set_msg_base(this->_servername, "376 "
                            + nickname
                            + ""
                            , ""
                            , ":End of /MOTD command.")
                            + "\r\n";
    (*this->_users_it)->add_to_queue(msg);
	return (SUCCESS);
}
