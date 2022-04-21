/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:38:42 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/21 17:19:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <errno.h>
# include <cstring>
# include <cstdio>
# include <iostream>
# include <cstdlib>
# include "defines.hpp"

class wrong_number_of_arguments : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class wrong_port_argument : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class wrong_password_argument : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class error_opening_socket : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class error_bind_failed : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class error_listen_failed : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class error_accept_failed : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class error_recv_failed : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class error_send_failed : public std::exception
{
	public:
		virtual const char*	what() const throw();
};


#endif
