/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:42:06 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"

void	check_nbr_of_arguments(int argc)
{
	if (argc != 3)
		throw wrong_number_of_arguments();
}

void	check_port_argument(const String & str)
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

void	check_password_argument(const String & str)
{
	if (str == "")
		throw wrong_password_argument();
}
