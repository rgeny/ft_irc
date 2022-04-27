/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.find.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:36:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 17:24:47 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

size_t	String::find	(const String & str
						,size_t pos) const
{
	size_t	str_size	= str.size(),
			this_size	= this->size();

	for (; pos < this_size; pos++)
	{
		if (this->compare(pos, str_size, str) == 0)
			return (pos);
	}
	return (std::string::npos);
}

size_t	String::find	(const char * s
						,size_t pos) const
{
	size_t	s_size		= strlen(s),
			this_size	= this->size();
	
	for (; pos < this_size; pos++)
	{
		if (this->compare(pos, s_size, s) == 0)
			return (pos);
	}
	return (std::string::npos);
}

size_t	String::find	(const char * s
						,size_t pos
						,size_t n) const
{
	size_t	s_size		= strlen(s),
			this_size	= this->size();
	
	for (; pos < this_size; pos++)
	{
		if (this->compare(pos, s_size, s, n) == 0)
			return (pos);
	}
	return (std::string::npos);
}

size_t	String::find	(char c
						,size_t pos) const
{
	size_t	this_size	= this->size();

	for (; pos < this_size; pos++)
	{
		if (this->_cast((*this)[pos]) == this->_cast(c))
			return (pos);
	}
	return (std::string::npos);
}
