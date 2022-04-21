/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:32:23 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/21 21:35:44 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::vector<std::string>	split	(std::string s
									,std::string delimiter)
{
	std::vector<std::string>	result;

	for (size_t pos = s.find(delimiter); pos != std::string::npos; pos = s.find(delimiter))
	{
		result.push_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}
	if (!s.empty())
		result.push_back(s);
	return (result);
}
