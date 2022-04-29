/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:32:23 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/29 04:24:03 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::vector<String>	split	(String s
							,String delimiter)
{
	std::vector<String>	result;

	for (size_t pos = s.find(delimiter); pos != String::npos; pos = s.find(delimiter))
	{
		if (pos > 0)
			result.push_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}
	if (!s.empty())
		result.push_back(s);
	return (result);
}

std::queue<String>	qsplit	(String s
							,String delimiter)
{
	std::queue<String>	result;

	for (size_t pos = s.find(delimiter); pos != String::npos; pos = s.find(delimiter))
	{
		if (pos > 0)
			result.push(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}
	if (!s.empty())
		result.push(s);
	return (result);
}
