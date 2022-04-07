/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:00:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/07 17:09:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include <iterator>

std::vector<int> *	casse	= new std::vector<int>();

static void	_fill_casse	(std::vector<int> &	casse)
{
	int				diff		= 'a' - 'A';

	for (int i = 0; i < 256; i++)
	{
		if (i >= 'a' && i <= '~')
			casse[i] = i - diff;
		else
			casse[i] = i;
	}
}

static void	_init_casse	(void)
{
//	std::vector<int> *	casse	= new std::vector<int>();
	casse->resize(256);
	_fill_casse(*casse);
}

bool	is_equal	(std::vector<std::string> &	arg
					,std::vector<int> &	casse)
{
	for (int i = 0; arg[0][i] != '\0' || arg[1][i] != '\0'; i++)
	{
		if (casse[arg[0][i]] != casse[arg[1][i]])
			return (false);
	}
	return (true);
}

int	main	(int		argc
			,char **	argv)
{
	if (argc < 3)
		return (0);
	std::vector<std::string>	arg	(argv + 1, argv + argc);
	_init_casse();
	std::cout	<< std::boolalpha
				<< is_equal(arg, *casse)
				<< std::endl;

	delete casse;
	return (0);
}


