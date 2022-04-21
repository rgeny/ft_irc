/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_proof.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:20:32 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/21 22:34:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::string case_proof(std::string str)
{
    size_t size = str.length();
    char char_str[size + 1]; 
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= '~')
            char_str[i] = str.c_str()[i] - 32;
        else 
            char_str[i] = str.c_str()[i];
    }
    char_str[size] = '\0';
    return (std::string(char_str));
}
