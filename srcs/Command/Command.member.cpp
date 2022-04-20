/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/20 11:02:09 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Command.hpp"
# include "Socket.hpp"
# include "ircserv.hpp"


void Command::parse(std::string cmd_str, Client *user)
{
    std::string tmp;
    this->tokens = split(cmd_str, ' ');
    for (size_t i = 0 ; i < this->tokens.get().size(); i++)
        r_trim(this->tokens.get()[i]);
    this->_user = user;
}