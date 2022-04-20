/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_trim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:46:06 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/16 09:48:25 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"

void r_trim(std::string &str)
{
    if (str[str.length() - 1] == '\r')
        str = str.substr(0, str.length() - 1);
}