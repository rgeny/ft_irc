/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chan_name.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:27:58 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/19 12:05:55 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool has_forbidden_char(String name)
{
    for (size_t i = 0; i < name.length(); i++)
        if (name[i] == 7 || name[i] == ',')
            return (true);
    return (false);
}

bool check_chan_name(String name)
{
    if (name.length() > 50)
        return (false);
  //  if (name[0] != '&' && name[0] != '#' && name[0] != '+' && name[0] != '!')
    if (name[0] != '#')
        return (false);
    if (has_forbidden_char(name) == true)
        return (false);
    return (true);
}

bool has_begin_hashtag(String name)
{
    if (name[0] == '#')
    //if (name[0] == '#' || name[0] == '&' || name[0] == '+' || name[0] == '!' )
        return (true);
    return (false);
}
