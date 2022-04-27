/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.find_last_of.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 17:22:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

size_t	String::find_last_of	(const String & str
								,size_t pos) const
{
	size_t	str_size	= str.size(),
			this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size; i <= this_size; i--)
	{
		for (size_t j = 0; j < str_size; j++)
		{
			if (this->_cast((*this)[i]) == this->_cast(str[j]))
				return (i);
		}
	}
	return (std::string::npos);
}

size_t	String::find_last_of	(const char * s
								,size_t pos) const
{
	size_t	s_size		= strlen(s),
			this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size; i <= this_size; i--)
	{
		for (size_t j = 0; j < s_size; j++)
		{
			if (this->_cast((*this)[i]) == this->_cast(s[j]))
				return (i);
		}
	}
	return (std::string::npos);
}

size_t	String::find_last_of	(const char * s
								,size_t pos
								,size_t n) const
{
	size_t	s_size		= std::min(strlen(s), n),
			this_size	= std::min(this->size(), pos);

	if (this_size > 0 && this_size != pos)
		this_size--;
	for (size_t i = this_size; i <= this_size; i--)
	{
		for (size_t j = 0; j < s_size; j++)
		{
			if (this->_cast((*this)[i]) == this->_cast(s[j]))
				return (i);
		}
	}
	return (std::string::npos);
}

size_t	String::find_last_of	(char c
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
