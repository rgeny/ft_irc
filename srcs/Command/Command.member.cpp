/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/13 13:07:31 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Command.hpp"
# include "Socket.hpp"


void Command::parse(std::string cmd_str, Client *user)
{
    this->tokens = split(cmd_str, ' ');
    this->_user = user;
}