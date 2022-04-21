/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:53:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 20:02:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool	is_special	(char c)
{
	return ((c >= '[' && c <= '`')
			|| (c >= '{' && c <= '}'));
}

bool	is_hexdigit	(char c)
{
	return ((c >= 'A' && c <= 'F')
			|| isdigit(c));
}

bool	is_number	(const std::string & str)
{
	return (str.find_first_not_of("0123456789") == std::string::npos);
}
