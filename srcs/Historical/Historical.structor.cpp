/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Historical.structor.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:56:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 11:08:59 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Historical.hpp"

Historical:: Historical	(void)
{
	std::cout	<< "Historical dfl constructor."
				<< std::endl;
}

Historical:: Historical	(Historical & src)
{
	std::cout	<< "Historical cpy constructor."
				<< std::endl;
	for (HISTORICAL_IT it = src._historical.begin(), ite = src._historical.end(); it != ite; it++)
	{
		this->_historical.push_back(new HistoricalNode(**it));
	}
}

Historical::~Historical	(void)
{
	for (HISTORICAL_IT it = this->_historical.begin(), ite = this->_historical.end(); it != ite; it++)
	{
		delete (*it);
	}
	std::cout	<< "Historical destructor."
				<< std::endl;
}

