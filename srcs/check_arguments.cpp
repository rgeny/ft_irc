/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:42:06 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/25 12:58:46 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"

void	check_nbr_of_arguments(int argc)
{
	if (argc != 3)
		throw wrong_number_of_arguments();
}

void	check_port_argument(const std::string & str)
{
	int port = atoi(str.c_str());

	if (str == ""
		|| is_number(str) == false
		|| port < PORT_MIN
		|| port > PORT_MAX)
	{
		throw wrong_port_argument();
	}
}

void	check_password_argument(const std::string & str)
{
	if (str == "")
		throw wrong_password_argument();
}
