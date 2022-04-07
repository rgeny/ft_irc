/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:00:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/07 15:56:08 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <iterator>


int	main	(int		argc
			,char **	argv)
{
	std::vector<std::string>	arg	(argv + 1, argv + argc);

	return (0);
}
