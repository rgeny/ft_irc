/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:57:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/10 17:48:31 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

Socket &	Socket::operator=	(Socket & src)
{
	(void)src;
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,Socket & src)
{
	(void)src;
	return (os);
}
