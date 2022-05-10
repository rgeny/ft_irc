/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:53:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 17:19:44 by rgeny            ###   ########.fr       */
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

bool	is_number	(const String & str)
{
	return (str.find_first_not_of("0123456789") == String::npos);
}

bool	is_mask		(char c)
{
	return (c == '*'
			|| c == '?'
			|| c == '\\');
}
