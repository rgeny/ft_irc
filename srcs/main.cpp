/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/10 19:18:45 by rgeny            ###   ########.fr       */
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
	catch (std::exception const & err)
	{
		return (print_error(err.what()));
	}
	return (EXIT_SUCCESS);
}
