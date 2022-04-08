/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:49:54 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/08 18:29:25 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ircserv.hpp"

const char *wrong_number_of_arguments::what() const throw()
{
	std::cerr	<< RED
				<< "Error: wrong number of arguments."
				<< "It should be ./ircserv <port> <password>"
				<< RESET
				<< std::endl;
	std::exit(EXIT_FAILURE);
	return ("");
}

const char *wrong_port_argument::what() const throw()
{
	std::cerr	<< RED
				<< "Error: the port argument has not the right format"
				<< RESET
				<< std::endl;
	std::exit(EXIT_FAILURE);
	return ("");
};

const char *wrong_password_argument::what() const throw()
{
	std::cerr	<< RED
				<< "Error: the password argument has not the right format"
				<< RESET
				<< std::endl;
	std::exit(EXIT_FAILURE);
	return ("");
};

const char *error_opening_socket::what() const throw()
{
	std::cerr	<< RED
				<< "Error: opening socket: "
				<< strerror(errno)
				<< RESET
				<< std::endl;
	std::exit(EXIT_FAILURE);
	return ("");
};

const char *error_bind_failed::what() const throw()
{
	std::cerr	<< RED
				<< "Error: bind_failed: "
				<< strerror(errno)
				<< RESET
				<< std::endl;
	std::exit(EXIT_FAILURE);
	return ("");
};

const char *error_listen_failed::what() const throw()
{
	std::cerr	<< RED
				<< "Error: listen_failed: "
				<< strerror(errno)
				<< RESET
				<< std::endl;
	std::exit(EXIT_FAILURE);
	return ("");
};
