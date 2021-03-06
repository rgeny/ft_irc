/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:49:54 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/30 18:51:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

const char *	wrong_number_of_arguments::what() const throw()
{
	return (ERROR_NBR_OF_ARGS);
}

const char *	wrong_port_argument::what() const throw()
{
	return (ERROR_PORT_ARG);
};

const char *	wrong_password_argument::what() const throw()
{
	return (ERROR_PASSWD_ARG);
};

const char *	error_opening_socket::what() const throw()
{
	return (ERROR_OPEN_SOCKET);
};


const char *	error_accept_failed::what() const throw()
{
	return (ERROR_ACCEPT);
};

const char *	error_recv_failed::what() const throw()
{
	return (ERROR_RECV);
};

const char *	error_send_failed::what() const throw()
{
	return (ERROR_SEND);
};
