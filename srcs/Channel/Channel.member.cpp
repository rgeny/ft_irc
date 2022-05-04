/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:37:12 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/04 18:31:19 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

bool Channel::has_topic()
{
    if (get_topic().empty() == true)
        return (false);
    return (true);
}

String Channel::get_mode_string()
{
    String chanmode_list = "aimnqpsrtklbeI";
    String chanmode_str = ":";
    int flag = 0;
    MODE_VEC chanmode_vec = get_mode();   
    for (size_t i = 0; i < chanmode_vec.size(); i++)
    {
        if (chanmode_vec[i] == true)
        {
            if (flag == 0)
            {
                chanmode_str += "+";
                flag = 1;
            }
            chanmode_str += chanmode_list[i];
        }
    }
    return (chanmode_str);
}