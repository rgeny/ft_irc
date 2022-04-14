/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.operator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:01:58 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/14 15:01:58 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User &	User::operator=	(User & src)
{
	(void)src;
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,User & src)
{
	(void)src;
	return (os);
}

