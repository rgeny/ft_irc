/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:33:30 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 21:14:16 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int	print_error	(String err)
{
	int	return_value = EXIT_FAILURE;
	std::cout	<< RED
				<< err;
	if (errno != 0)
	{
		std::cout	<< strerror(errno);
		return_value = errno;
	}
	std::cout	<< RESET
				<<std::endl;
	return (return_value);
}
