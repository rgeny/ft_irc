/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.find_last_not_of.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 19:07:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

size_t	String::find_last_not_of	(const String & str
									,size_t pos) const
{
	return (this->find_last_not_of(str.c_str(), pos, str.size()));
}

size_t	String::find_last_not_of	(const char * s
									,size_t pos) const
{
	return (this->find_last_not_of(s, pos, strlen(s)));
}

size_t	String::find_last_not_of	(const char * s
									,size_t pos
									,size_t n) const
{
	size_t	this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size, tmp = i; i <= this_size; i--)
	{
		tmp = this->find_last_of(s, i, n);
		if (i != tmp)
			return (i);
		i = tmp;
	}
	return (std::string::npos);
}

size_t	String::find_last_not_of	(char c
									,size_t pos) const
{
	String	tmp(1, c);
	return (this->find_last_not_of(tmp.c_str(), pos, 1));
}
