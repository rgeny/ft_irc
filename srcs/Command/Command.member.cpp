/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/15 19:50:00 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Command.hpp"
# include "Socket.hpp"


void Command::parse(std::string cmd_str, Client *user, int flag = 0)
{
    this->tokens = split(cmd_str, ' ');
    if (flag)
    {
        std::string last_token = this->tokens.get()[this->tokens.get().size()];
        last_token.substr(0, last_token.length() - 2);
    }
    this->_user = user;
}