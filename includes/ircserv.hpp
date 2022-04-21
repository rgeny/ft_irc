/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:46:14 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/21 17:17:24 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERV_HPP
# define IRCSERV_HPP

# include <iostream>
# include <string>
# include <cstdlib>
//# include <ctime>
//
# include <vector>
//# include <map>
//# include <sstream>
//
//# include "Message.hpp"
//
//# include "Exceptions.hpp"

void	check_nbr_of_arguments	(int argc);
void	check_port_argument	(const std::string & str);
void	check_password_argument	(const std::string & str);
bool    is_number	(const std::string& str);
//void	ircserv	(int port
//				,std::string const & password);
bool	is_special	(char c);
bool	is_hexdigit	(char c);
std::vector<std::string>	split	(std::string	&s
									,std::string	delimiter);
std::string case_proof(std::string str);

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
