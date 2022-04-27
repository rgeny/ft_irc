/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:32:23 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/27 20:22:33 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::vector<String>	split	(String s
									,String delimiter)
{
	std::vector<String>	result;

	for (size_t pos = s.find(delimiter); pos != String::npos; pos = s.find(delimiter))
	{
		result.push_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}
	if (!s.empty())
		result.push_back(s);
	return (result);
}
