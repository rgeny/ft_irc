/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:45 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/18 19:16:25 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

std::string const & Message::aggreg(void)
{
    std::string *tmp = new std::string(_sender + " " + msg_code.get() + " " + _receiver + " " + msg_content.get() + "\r\n");
    return (*tmp);
}