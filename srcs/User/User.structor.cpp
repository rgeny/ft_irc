/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.structor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:01:53 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/14 16:15:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User:: User	(void): nickname("anonymous")
{
	std::cout	<< "User dfl constructor."
				<< std::endl;
}

User:: User	(User const & src)
{
	(void)src;
	std::cout	<< "User cpy constructor."
				<< std::endl;
}

User::~User	(void)
{
	std::cout	<< "User destructor."
				<< std::endl;
}

