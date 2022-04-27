/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:46:14 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/27 20:42:27 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERV_HPP
# define IRCSERV_HPP

# include <iostream>
# include <cstdlib>
# include <vector>

# include "defines.hpp"
# include "Exceptions.hpp"
# include "Utils.hpp"

void	check_nbr_of_arguments	(int argc);
void	check_port_argument		(const String & str);
void	check_password_argument	(const String & str);

/*
**  TEMPLATES
*/
template <typename T>
void	print_variable	(String color
						,String txt
						,T var
						,String reset)
{
	std::cout   << color
				<< txt
				<< var
				<< reset
				<< std::endl;	
}

#endif
