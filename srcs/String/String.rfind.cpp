/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.rfind.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:23:16 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 17:26:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

size_t	String::rfind	(const String & str
						,size_t pos) const
{
	size_t	str_size	= str.size(),
			this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size; i <= this_size; i--)
	{
		if (this->compare(i, str_size, str) == 0)
			return (i);
	}
	return (std::string::npos);
}


size_t	String::rfind	(const char * s
						,size_t pos) const
{
	size_t	s_size		= strlen(s),
			this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size; i <= this_size; i--)
	{
		if (this->compare(i, s_size, s) == 0)
			return (i);
	}
	return (std::string::npos);
}

size_t	String::rfind	(const char * s
						,size_t pos
						,size_t n) const
{
	size_t	s_size		= strlen(s),
			this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size; i <= this_size; i--)
	{
		if (this->compare(i, n, s, n) == 0)
			return (i);
	}
	return (std::string::npos);
}

size_t	String::rfind	(char c
						,size_t pos) const
{
	size_t	this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size; i <= this_size; i--)
	{
		if (this->_cast((*this)[i]) == this->_cast(c))
			return (i);
	}
	return (std::string::npos);
}
