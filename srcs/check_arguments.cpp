/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:42:06 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 17:52:40 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ircserv.hpp"

void	check_nbr_of_arguments(int argc)
{
	try
	{
		if (argc != 3)
		{
			throw wrong_number_of_arguments();
		}
	}
	catch(const wrong_number_of_arguments& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	check_port_argument(const std::string & str)
{
	try
	{
		if (str == "" ||
			is_number(str) == false ||
			str.length() > 5 ||
			atoi(str.c_str()) < 0)
		{
			throw wrong_port_argument();
		}
	}
	catch(const wrong_port_argument & e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	check_password_argument(const std::string & str)
{
	try
	{
		if (str == "")
		{
			throw wrong_password_argument();
		}
	}
	catch(const wrong_password_argument& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
