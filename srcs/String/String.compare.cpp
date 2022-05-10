/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.compare.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:41:40 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 19:18:27 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

bool	String::_is_valid_name	(size_t i
								,size_t len
								,const String & str
								,size_t j
								,size_t & k
								,size_t sublen
								,size_t & l) const
{
	for (l = 0; (i + k + l) < len && (l == 0 || !is_mask((*this)[i + k + l])); l++)
	{
		if (this->_cast((*this)[i + k + l]) != this->_cast(str[j + k + l]))
			return (false);
	}
	if (is_mask((*this)[i + k + l])
		|| ((i + k + l) == len
			&& (j + k + l) == sublen))
	{
		k += l;
		return (true);
	}
	return (false);
}

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

	for (size_t i = pos, j = subpos, k = 0, l = 0; (i + k) < len || (j + k) < sublen;)
	{
		if ((i + k) < len
			&& (*this)[i + k] == '\\')
		{
			i++;
			if (!this->_is_valid_name(i, len, str, j, k, sublen, l))
				return (this->_cast((*this)[i + k + l]) - this->_cast(str[j + k + l]));
		}
		else if ((*this)[i + k] == '?')
		{
			if ((j + k) < sublen)
				k++;
			else
				i++;
		}
		else if ((*this)[i + k] == '*')
		{
			while ((i + k) < len
					&& (*this)[i + k] == '*')
			{
				i++;
			}
			while ((j + k) < sublen
				&& !this->_is_valid_name(i, len, str, j, k, sublen, l))
			{
				j++;
			}
		}
		else if (!this->_is_valid_name(i, len, str, j, k, sublen, l))
			return (this->_cast((*this)[i + k + l]) - this->_cast(str[j + k + l]));
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
