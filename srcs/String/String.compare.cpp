/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.compare.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:41:40 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 15:33:53 by rgeny            ###   ########.fr       */
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









bool	String::_is_valid_name	(size_t i
								,size_t len
								,const String & str
								,size_t j
								,size_t & k
								,size_t sublen
								,size_t & l) const
{
	l = 0;

	while ((i + k + l) < len
			&& (((*this)[i + k + l] != '*'
				&& (*this)[i + k + l] != '?'
				&& (*this)[i + k + l] != '\\')
			|| l == 0))
	{
		std::cout	<< "t8\n";
		if (this->_cast((*this)[i + k + l]) != this->_cast(str[j + k + l]))
			return (false);
		l++;
	}
	if ((*this)[i + k + l] == '*'
		|| (*this)[i + k + l] == '?'
		|| (*this)[i + k + l] == '\\'
		|| ((i + k + l) == len
			&& (j + k + l) == sublen))
	{
		k += l;
		return (true);
	}
	return (false);
}
//		if (this->_cast((*this)[i]) != this->_cast(str[j]))
//			return (this->_cast((*this)[i]) - this->_cast(str[j]));
//








int	String::compare	(size_t pos
					,size_t len
					,const String & str
					,size_t subpos
					,size_t sublen) const
{
	len = std::min(len + pos, this->size());
	sublen = std::min(sublen + subpos, str.size());




	bool	escape = false,
			asterisk = false;
	size_t	i,
			j,
			k,
			l;

	for (i = pos, j = subpos, k = 0; i + k < len || j + k < sublen;)
	{
		std::cout	<< "t1\n";
		if (!escape && (*this)[i + k] == '\\' && (i + k) < len)
		{
			std::cout	<< "t2\n";
			escape = true;
			i++;
		}
		else if (!escape && (*this)[i + k] == '?')
		{
			std::cout	<< "t3\n";
			if (j + k != sublen)
				j++;
			i++;
		}
		else if (!escape && (*this)[i + k] == '*')
		{
			std::cout	<< "t4\n";
			while ((*this)[i + k] == '*' && (i + k) < len)
				i++;
			asterisk = true;
		}
		else if (asterisk == true)
		{
			std::cout	<< "t5\n";
			while ((j + k) != sublen
				&& !this->_is_valid_name(i, len, str, j, k, sublen, l))
			{
				j++;
			}
			asterisk = false;
			escape = false;
		}
		else
		{
			std::cout	<< "t6\n";
			if (!this->_is_valid_name(i, len, str, j, k, sublen, l))
				return (this->_cast((*this)[i + k + l]) - this->_cast(str[j + k + l]));
			std::cout	<< "t7\n";
			escape = false;
		}
	}


	return ((len - (i + k)) - (sublen - (j + k)));
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
