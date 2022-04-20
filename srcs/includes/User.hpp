/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:02:13 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 16:18:20 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include <string>

#include "Accessor.hpp"

class User
{
	private:
		User();
	
	public:
		Accessor<std::string>	username;
		Accessor<std::string>	nickname;
		Accessor<std::string>	hostname;
		Accessor<std::string>	realname;
		Accessor<std::string>	mode;

		User(std::string const & username
			,std::string const & nickname
			,std::string const & hostname
			,std::string const & realname
			,std::string const & mode);
		User( User const & src);
		User & operator=(User const & rhs);
		~User();

};

std::ostream&	operator<<( std::ostream& o, User const & instance);

#endif