/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Historical.operator.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:05:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 12:46:28 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Historical.hpp"

Historical &	Historical::operator=	(Historical & src)
{
	src._clear_history();

	HISTORICAL_IT	it	= src._historical.begin();
	HISTORICAL_IT	ite	= src._historical.end();

	while (it != ite)
	{
		this->_historical.push_back(new HistoricalNode(**it));
		it++;
	}

	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,Historical & src)
{
	(void)src;
	return (os);
}

