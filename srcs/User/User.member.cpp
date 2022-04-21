/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:02:03 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/21 14:29:18 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

std::string User::fci(void){
    return(nickname.get() + "!" + username.get() + "@" + hostname.get());
}

bool User::is_nick_valid(std::string const & nickname)
{
    if (nickname.length() > 9)
        return (false);
    for (size_t i = 0 ; i < nickname.length(); i++)
    {
        if (nickname[i] < 65 || nickname[i] > 126 || nickname[i] == 94)
            return (false);
    }
    return (true);
}