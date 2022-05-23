/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.find.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:36:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/23 10:32:17 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

size_t	String::find	(const std::string & str) const
{
	return (this->std::string::find(str, 0));
}

size_t	String::find	(const String & str
						,size_t pos) const
{
	return (this->find(str.c_str(), pos, str.size()));
}

size_t	String::find	(const char * s
						,size_t pos) const
{
	return (this->find(s, pos, strlen(s)));
}

size_t	String::find	(const char * s
						,size_t pos
						,size_t n) const
{
	size_t	this_size	= this->size();
	
	for (; pos < this_size; pos++)
	{
		if (this->compare(pos, n, s, n) == 0)
			return (pos);
	}
	return (std::string::npos);
}

size_t	String::find	(char c
						,size_t pos) const
{
	String	tmp(1, c);
	return (this->find(tmp.c_str(), pos, 1));
}
