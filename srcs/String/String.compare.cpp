/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.compare.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:41:40 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 18:38:54 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

int		String::compare	(const String & str) const
{
	return (this->compare(0, this->size(), str, 0, str.size()));
}

int		String::compare	(size_t pos
						,size_t len
						,const String & str) const
{
	return (this->compare(pos, len, str, 0, str.size()));
}

int	String::compare	(size_t pos
					,size_t len
					,const String & str
					,size_t subpos
					,size_t sublen) const
{
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
	String	tmp(s);
	return (this->compare(0, this->size(), tmp, 0, tmp.size()));
}

int		String::compare	(size_t pos
						,size_t len
						,const char * s) const
{
	String	tmp(s);
	return (this->compare(pos, len, tmp, 0, tmp.size()));

}

int	String::compare	(size_t pos
					,size_t len
					,const char * s
					,size_t n) const
{
	String	tmp(s);
	return (this->compare(pos, len, tmp, 0, n));
}
