/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:56 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/12 17:34:35 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Command.hpp"
# include "Socket.hpp"

void Command::parse(std::string cmd_str, Client *user)
{
    this->cmd = split(cmd_str, ' ');
    this->_user = user;
}