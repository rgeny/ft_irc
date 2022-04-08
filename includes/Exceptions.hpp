/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:38:42 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/08 18:15:56 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include "ircserv.hpp"
# include <errno.h>
# include <cstring>
# include <cstdio>

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

#endif
