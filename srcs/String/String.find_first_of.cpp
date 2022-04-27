/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.find_first_of.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:23:03 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 17:23:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

size_t	String::find_first_of	(const String & str
								,size_t pos) const
{
	size_t	str_size	= str.size(),
			this_size	= this->size();

	for (; pos < this_size; pos++)
	{
		for (size_t j = 0; j < str_size; j++)
		{
			if (this->_cast((*this)[pos]) == this->_cast(str[j]))
				return (pos);
		}
	}
	return (std::string::npos);
}

size_t	String::find_first_of	(const char * s
								,size_t pos) const
{
	size_t	s_size		= strlen(s),
			this_size	= this->size();

	for (;pos < this_size; pos++)
	{
		for (size_t j = 0; j < s_size; j++)
		{
			if (this->_cast((*this)[pos]) == this->_cast(s[j]))
				return (pos);
		}
	}
	return (std::string::npos);
}


size_t	String::find_first_of	(const char * s
								,size_t pos
								,size_t n) const
{
	size_t	s_size		= std::min(strlen(s), n),
			this_size	= this->size();

	for (; pos < this_size; pos++)
	{
		for (size_t j = 0; j < s_size; j++)
		{
			if (this->_cast((*this)[pos]) == this->_cast(s[j]))
				return (pos);
		}
	}
	return (std::string::npos);
}

size_t	String::find_first_of	(char c
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
