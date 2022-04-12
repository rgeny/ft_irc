/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:08 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/12 10:31:08 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command &	Command::operator=	(Command & src)
{
	(void)src;
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,Command & src)
{
	(void)src;
	return (os);
}

