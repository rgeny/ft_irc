/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.structor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:25 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/12 10:31:25 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command:: Command	(void)
{
	std::cout	<< "Command dfl constructor."
				<< std::endl;
}

Command:: Command	(Command & src)
{
	(void)src;
	std::cout	<< "Command cpy constructor."
				<< std::endl;
}

Command::~Command	(void)
{
	std::cout	<< "Command destructor."
				<< std::endl;
}

