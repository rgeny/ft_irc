/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:06:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 15:19:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

bool	operator==	(const String & lhs
					,const String & rhs)
{
	return (lhs.compare(rhs) == 0);
}

bool	operator==	(const char * lhs
					,const String & rhs)
{
	return (rhs.compare(lhs) == 0);
}

bool	operator==	(const String & lhs
					,const char * rhs)
{
	return (lhs.compare(rhs) == 0);
}

bool 	operator!=	(const String & lhs
					,const String & rhs)
{
	return (lhs.compare(rhs) != 0);
}

bool 	operator!=	(const char * lhs
					,const String & rhs)
{
	return (rhs.compare(lhs) != 0);
}

bool 	operator!=	(const String & lhs
					,const char * rhs)
{
	return (lhs.compare(rhs) != 0);
}

bool 	operator<	(const String & lhs
					,const String & rhs)
{
	return (lhs.compare(rhs) < 0);
}

bool 	operator<	(const char * lhs
					,const String & rhs)
{
	return (rhs.compare(lhs) > 0);
}

bool 	operator<	(const String & lhs
					,const char * rhs)
{
	return (lhs.compare(rhs) < 0);
}

bool 	operator<=	(const String & lhs
					,const String & rhs)
{
	return (lhs.compare(rhs) <= 0);
}

bool 	operator<=	(const char * lhs
					,const String & rhs)
{
	return (rhs.compare(lhs) >= 0);
}

bool 	operator<=	(const String & lhs
					,const char * rhs)
{
	return (lhs.compare(rhs) <= 0);
}

bool 	operator>	(const String & lhs
					,const String & rhs)
{
	return (lhs.compare(rhs) > 0);
}

bool 	operator>	(const char * lhs
					,const String & rhs)
{
	return (rhs.compare(lhs) < 0 );
}

bool 	operator>	(const String & lhs
					,const char * rhs)
{
	return (lhs.compare(rhs) > 0);
}

bool 	operator>=	(const String & lhs
					,const String & rhs)
{
	return (lhs.compare(rhs) >= 0);
}

bool 	operator>=	(const char * lhs
					,const String & rhs)
{
	return (rhs.compare(lhs) <= 0);
}

bool 	operator>=	(const String & lhs
					,const char * rhs)
{
	return (lhs.compare(rhs) >= 0);
}
