/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:27 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/08 17:31:27 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server &	Server::operator=	(Server & src)
{
	(void)src;
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,Server & src)
{
	(void)src;
	return (os);
}

