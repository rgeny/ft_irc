/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HistoricalNode.operator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:32:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 10:52:39 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HistoricalNode.hpp"

HistoricalNode &	HistoricalNode::operator=	(HistoricalNode & src)
{
	(void)src;
	return (*this);
}

std::ostream &	operator<<	(std::ostream & 	os
							,HistoricalNode &	src)
{
	os	<< "last      : "
		<< src.get_last()
		<< std::endl
		<< "actual    : "
		<< src.get_actual()
		<< std::endl
		<< "timestamp : "
		<< src.get_timestamp()
		<< std::endl;
	return (os);
}
