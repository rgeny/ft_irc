/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:45 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/16 01:50:34 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

std::string const & Message::aggreg(void)
{
    std::string *tmp = new std::string(_sender + " " + txt.get() + " " + _receiver + " " + commandCalled.get() + "\r\n");
    return (*tmp);
}