/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:38:41 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 21:38:41 by rgeny            ###   ########.fr       */
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

