/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_case_off.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:45:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 02:33:15 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

void	String::_init_case_off	(void)
{
	if (String::_case_off.empty())
	{
		int	diff_low_up = 'a' - 'A';

		String::_case_off.resize(256);
		for (int i = 0; i < 256; i++)
		{
			if (i >= 'a' && i <= '~')
				String::_case_off[i] = (i - diff_low_up);
			else
				String::_case_off[i] = i;
		}
	}
}
