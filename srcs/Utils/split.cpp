/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:32:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/18 12:51:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::vector<String>	split	(String s
							,String delimiter)
{
	std::vector<String>	result;
	std::string	tmp(s);

	for (size_t pos = tmp.find(delimiter); pos != String::npos; pos = tmp.find(delimiter))
	{
		if (pos > 0)
			result.push_back(s.substr(0, pos));
		tmp.erase(0, pos + delimiter.length());
	}
	if (!tmp.empty())
		result.push_back(tmp);
	return (result);
}

std::queue<String>	qsplit	(String s
							,String delimiter)
{
	std::queue<String>	result;
	std::string	tmp(s);

	for (size_t pos = tmp.find(delimiter); pos != String::npos; pos = tmp.find(delimiter))
	{
		if (pos > 0)
			result.push(tmp.substr(0, pos));
		tmp.erase(0, pos + delimiter.length());
	}
	if (!tmp.empty())
		result.push(tmp);
	s.erase();
	return (result);
}
