/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:23:38 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/21 10:53:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"
#include "Socket.hpp"
#include "Server.hpp"
#include "User.hpp"
#include "HistoricalNode.hpp"

bool	is_number(const std::string& str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

int	main	(__attribute((unused)) int argc
			,__attribute((unused)) char ** argv)
{
	{
		HistoricalNode	a("abc", "def");

		std::cout	<< std::endl
					<< a
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
		print_variable(BOLDMAGENTA, "ft_irc started", "", RESET);
		port = atoi(argv[1]);
		password = argv[2];
		Server	serv (password, port);

		serv.main();
	}
	catch (const wrong_number_of_arguments & e)
	{
		e.what();
	}
	catch (const wrong_port_argument & e)
	{
		e.what();
	}
	catch (const wrong_password_argument & e)
	{
		e.what();
	}
	catch (const error_opening_socket & e)
	{
		e.what();
	}
	catch (const error_bind_failed & e)
	{
		e.what();
	}
	catch (const error_listen_failed & e)
	{
		e.what();
	}
	return (EXIT_SUCCESS);
}
//	Socket	x;
//	std::cout	<< x
//				<< std::endl;
//	
//	SOCKADDR_IN	sin;
//	sin.sin_addr.s_addr = htonl(INADDR_ANY);
//	sin.sin_port		= htons(6697);
//	sin.sin_family		= AF_INET;
//	bind(x.get_socket(), (SOCKADDR *) &sin, sizeof (sin));
//	std::cout	<< "a"
//				<< std::endl;
//	listen(x.get_socket(), 10);
//	std::cout	<< "b"
//				<< std::endl;
