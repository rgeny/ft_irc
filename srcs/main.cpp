/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/27 15:15:03 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"
#include "Socket.hpp"
#include "Server.hpp"
#include "User.hpp"

#include "String.hpp"

int	main	(__attribute((unused)) int argc
			,__attribute((unused)) char ** argv)
{
	{
		std::string	a("abcdefg"),
					b("b"),
					c("bbb");
		char		d[] = "abcdeg";

		if (d < b)
			std::cout	<< "a == b"
						<< std::endl;
		else
			std::cout	<< "a != b"
						<< std::endl;
	}
	{
		String	a("abcdefgh"),
				b("b"),
				c("bbb");
		char		d[] = "abcdeg";

		if (d < b)
			std::cout	<< "a == b"
						<< std::endl;
		else
			std::cout	<< "a != b"
						<< std::endl;
	}
	return (0);








	try
	{
		int	port;
		std::string	password;

		check_nbr_of_arguments(argc);
		check_port_argument(std::string(argv[1]));
		check_password_argument(std::string(argv[2]));
		print_variable(BOLD MAGENTA, "ft_irc started", "", RESET);
		port = atoi(argv[1]);
		password = argv[2];
		Server	serv (password, port);

		serv.main();
	}
	catch (const wrong_number_of_arguments & e)
	{
		return (print_error(e.what()));
	}
	catch (const wrong_port_argument & e)
	{
		return (print_error(e.what()));
	}
	catch (const wrong_password_argument & e)
	{
		return (print_error(e.what()));
	}
	catch (const error_opening_socket & e)
	{
		return (print_error(e.what()));
	}
	return (EXIT_SUCCESS);
}
