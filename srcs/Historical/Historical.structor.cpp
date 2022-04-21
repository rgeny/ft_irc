/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Historical.structor.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:56:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 12:46:42 by rgeny            ###   ########.fr       */
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
	
	HISTORICAL_IT	it	= src._historical.begin();
	HISTORICAL_IT	ite	= src._historical.end();

	while (it != ite)
	{
		this->_historical.push_back(new HistoricalNode(**it));
		it++;
	}
}

Historical::~Historical	(void)
{
	this->_clear_history();
	std::cout	<< "Historical destructor."
				<< std::endl;
}
