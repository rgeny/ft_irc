/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/26 15:35:14 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"
#include "Socket.hpp"
#include "Server.hpp"
#include "User.hpp"

int	main	(__attribute((unused)) int argc
			,__attribute((unused)) char ** argv)
{
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
//		std::cout	<< std::endl;
//		Server	scpy(serv);
//		std::cout	<< std::endl;

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
