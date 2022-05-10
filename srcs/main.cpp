/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/10 17:36:47 by rgeny            ###   ########.fr       */
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
	try
	{
		int	port;
		String	password;

		check_nbr_of_arguments(argc);
		check_port_argument(String(argv[1]));
		check_password_argument(String(argv[2]));
		print_server_name();
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
