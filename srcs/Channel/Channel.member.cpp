/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:37:12 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/20 12:49:03 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include <string>

bool Channel::has_topic()
{
    if (get_topic().empty() == true)
        return (false);
    return (true);
}

String Channel::add_final_colon(String args_list)
{
	String  mod_list;

	std::vector<String> splitted_args_list = split(args_list, " ");
	
	for (std::vector<String>::iterator it = splitted_args_list.begin(), ite = splitted_args_list.end(); it != ite; it++)
	{
		if (it != ite - 1)
			mod_list = mod_list + *it + " ";
		else
			mod_list = mod_list + ":" + *it;
	}
	return (mod_list);
}

String Channel::get_mode_string()
{
    String chanmode_list = "aimnqpsrtklbeI";
    String chanmode_str = ":+";
    MODE_VEC chanmode_vec = get_mode();
    String args_list;
    for (size_t i = 0; i < chanmode_vec.size(); i++)
    {
        if (chanmode_vec[i] == true)
        {
            chanmode_str += chanmode_list[i];
            if (chanmode_list[i] == 'l')
            {
                size_t limit = get_limit();
                std::stringstream ss;
                ss << limit;
                std::string str = ss.str();

                args_list += String(str) + " ";
            }
            if (chanmode_list[i] == 'k')
                args_list += get_key() + " ";
        }
    }
    chanmode_str += " " + add_final_colon(args_list);
    
    return (chanmode_str);
}