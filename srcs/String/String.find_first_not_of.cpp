/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.find_first_not_of.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:22:31 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 17:22:39 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

size_t	String::find_first_not_of	(const String & str
									,size_t pos) const
{
	size_t	this_size	= this->size();

	for (size_t tmp = pos; pos < this_size; pos++)
	{
		tmp = this->find_first_of(str, pos);
		if (pos != tmp)
			return (pos);
		pos = tmp;
	}
	return (std::string::npos);
}

size_t	String::find_first_not_of	(const char * s
									,size_t pos) const
{
	size_t	this_size	= this->size();

	for (size_t tmp = pos; pos < this_size; pos++)
	{
		tmp = this->find_first_of(s, pos);
		if (pos != tmp)
			return (pos);
		pos = tmp;
	}
	return (std::string::npos);
}

size_t	String::find_first_not_of	(const char * s
									,size_t pos
									,size_t n) const
{
	size_t	this_size	= this->size();

	for (size_t tmp = pos; pos < this_size; pos++)
	{
		tmp = this->find_first_of(s, pos, n);
		if (pos != tmp)
			return (pos);
		pos = tmp;
	}
	return (std::string::npos);
}

size_t	String::find_first_not_of	(char c
									,size_t pos) const
{
	size_t	this_size	= this->size();

	for (size_t tmp = pos; pos < this_size; pos++)
	{
		tmp = this->find_first_of(c, pos);
		if (pos != tmp)
			return (pos);
		pos = tmp;
	}
	return (std::string::npos);
}
