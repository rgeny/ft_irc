/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:46:14 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 19:38:13 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERV_HPP
# define IRCSERV_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include <arpa/inet.h> //htons
#include <unistd.h> // close

#include <sys/socket.h>

#include "defines.hpp"
#include "User.hpp"
#include "Channel.hpp"
#include "Message.hpp"

#include "Exceptions.hpp"

void	check_nbr_of_arguments(int argc);
void	check_port_argument(const std::string & str);
void	check_password_argument(const std::string & str);

bool    is_number(const std::string& str);

void	ircserv(int port, std::string const & password);

/*
**  TEMPLATES
*/
template < typename T>
void	print_variable(std::string color
						,std::string txt
						,T var
						,std::string reset)
{
	std::cout   << color
				<< txt
				<< var
				<< reset
				<< std::endl;	
}

#endif
