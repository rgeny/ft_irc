/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HistoricalNode.structor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:29:45 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:39:20 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HistoricalNode.hpp"

HistoricalNode:: HistoricalNode	(void)
	:_timestamp(time(NULL))
{
	std::cout	<< "HistoricalNode dfl constructor."
				<< std::endl;
}

HistoricalNode:: HistoricalNode	(String last
								,String actual)
	:_last(last)
	,_actual(actual)
	,_timestamp(time(NULL))
{
	std::cout	<< "HistoricalNode parameter constructor."
				<< std::endl;
}

HistoricalNode:: HistoricalNode	(HistoricalNode & src)
	:_last(src._last)
	,_actual(src._actual)
	,_timestamp(src._timestamp)
{
	std::cout	<< "HistoricalNode cpy constructor."
				<< std::endl;
}

HistoricalNode::~HistoricalNode	(void)
{
	std::cout	<< "HistoricalNode destructor."
				<< std::endl;
}

