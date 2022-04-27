/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.compare.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:41:40 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 14:53:09 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

int		String::compare	(const String & str) const
{
	size_t	str_size	= str.size();
	size_t	this_size	= this->size();
	size_t	min_size	= std::min(str_size, this_size);

	for (size_t i = 0; i < min_size; i++)
	{
		if (this->_cast((*this)[i]) != this->_cast(str[i]))
			return (this->_cast((*this)[i]) - this->_cast(str[i]));
	}
	return (this_size - str_size);
}

int		String::compare	(size_t pos
						,size_t len
						,const String & str) const
{
	if (pos > this->size())
		return (this->std::string::compare(pos, len, str));

	len = std::min(len + pos, this->size());

	size_t	str_size	= str.size();

	for (size_t i = pos, j = 0; i < len && j < str_size; i++, j++)
	{
		if (this->_cast((*this)[i]) != this->_cast(str[j]))
			return (this->_cast((*this)[i]) - this->_cast(str[j]));
	}

	return ((len - pos) - str_size);
}

int	String::compare	(size_t pos
					,size_t len
					,const String & str
					,size_t subpos
					,size_t sublen) const
{
	if (pos > this->size()
		|| subpos > str.size())
	{
		return (this->std::string::compare(pos, len, str, subpos, sublen));
	}

	len = std::min(len + pos, this->size());
	sublen = std::min(sublen + subpos, str.size());

	for (size_t i = pos, j = subpos; i < len && j < sublen; i++, j++)
	{
		if (this->_cast((*this)[i]) != this->_cast(str[j]))
			return (this->_cast((*this)[i]) - this->_cast(str[j]));
	}

	return ((len - pos) - (sublen - subpos));
}

int		String::compare	(const char * s) const
{
	size_t	s_size		= strlen(s);
	size_t	this_size	= this->size();
	size_t	size_min	= std::min(s_size, this_size);

	for (size_t i = 0; i < size_min; i++)
	{
		if (this->_cast((*this)[i]) != this->_cast(s[i]))
			return (this->_cast((*this)[i]) - this->_cast(s[i]));
	}

	return (this_size - s_size);
}

int		String::compare	(size_t pos
						,size_t len
						,const char * s) const
{
	if (pos > this->size())
		return (this->std::string::compare(pos, len, s));

	len = std::min(len + pos, this->size());

	size_t	s_size	= strlen(s);

	for (size_t i = pos, j = 0; i < len && j < s_size; i++, j++)
	{
		if (this->_cast((*this)[i]) != this->_cast(s[j]))
			return (this->_cast((*this)[i]) - this->_cast(s[j]));
	}

	return ((len - pos) - s_size);
}

int	String::compare	(size_t pos
					,size_t len
					,const char * s
					,size_t n) const
{
	if (pos > this->size()
		|| n > strlen(s))
	{
		return (this->std::string::compare(pos, len, s, n));
	}

	len = std::min(len + pos, this->size());

	for (size_t i = pos, j = 0; i < len && j < n; i++, j++)
	{
		if (this->_cast((*this)[i]) != this->_cast(s[j]))
			return (this->_cast((*this)[i]) - this->_cast(s[j]));
	}

	return ((len - pos) - n);
}
