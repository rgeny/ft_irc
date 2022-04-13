/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/13 11:49:36 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Command.hpp"
# include "Socket.hpp"


void Command::parse(std::string cmd_str, Client *user)
{
    this->cmd = split(cmd_str, ' ');
    this->_user = user;
    check_cmd(this->cmd);
}

void Command::check_cmd(std::string cmd)
{
    
}