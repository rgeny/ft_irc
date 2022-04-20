/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:32:23 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/20 14:52:14 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ircserv.hpp"

std::vector<std::string>	split	(std::string	&s
									,std::string	delimiter)
{
	std::vector<std::string>	result;
	size_t pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		result.push_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}
	if (!s.empty())
		result.push_back(s);
	return result;
}
