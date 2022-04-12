/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:32:23 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/12 15:43:24 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ircserv.hpp"

std::vector<std::string>	split	(const std::string &s
									,char delim)
{
	std::vector<std::string>	result;
	std::stringstream			ss (s);
	std::string					item;


	while (getline (ss, item, delim))
	{
		result.push_back (item);
	}
	return result;
}
