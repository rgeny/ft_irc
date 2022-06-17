/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/17 08:01:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <csignal>

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
		signal(SIGINT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
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
	catch (std::exception const & err)
	{
		return (print_error(err.what()));
	}
	return (EXIT_SUCCESS);
}
