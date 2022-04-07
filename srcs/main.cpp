/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/07 16:01:48 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ircserv.hpp"


bool	is_number(const std::string& str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

int	main(int argc, char ** argv)
{
	int	port;
	std::string	password;

	check_nbr_of_arguments(argc);
	check_port_argument(std::string(argv[1]));
	check_password_argument(std::string(argv[2]));
	print_variable(BOLDMAGENTA, "ft_irc started", "", RESET);
	port = atoi(argv[1]);
	password = argv[2];

	ircserv(port, password);
	
	return (EXIT_SUCCESS);
}
