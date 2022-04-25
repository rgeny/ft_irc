/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Historical.member.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:05:09 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 17:29:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Historical.hpp"

void	Historical::new_node	(std::string last
								,std::string actual)
{
	this->_rm_obsolete_history();

	if (last != actual)
		this->_historical.push_back(new HistoricalNode(last, actual));
}

std::string	Historical::find_actual	(std::string nickname)
{
	this->_rm_obsolete_history();

	HISTORICAL_IT	it	= this->_historical.begin();
	HISTORICAL_IT	ite	= this->_historical.end();

	while (it != ite)
	{
		if (nickname == (*it)->get_last())
			nickname = (*it)->get_actual();
		it++;
	}
	return (nickname);
}

bool	Historical::nick_is_lock	(std::string & nickname)
{
	this->_rm_obsolete_history();

	HISTORICAL_IT	it	= this->_historical.begin();
	HISTORICAL_IT	ite	= this->_historical.end();

	while (it != ite)
	{
		if (nickname == (*it)->get_last()
			|| nickname == (*it)->get_actual())
		{
			return (true);
		}
		it++;
	}
	return (false);
}

void	Historical::_rm_obsolete_history	(void)
{
	std::vector<HistoricalNode *> &	historical	= this->_historical;
	HISTORICAL_IT					it			= historical.begin();
	HISTORICAL_IT					ite			= historical.end();

	while (it != ite
			&& (*it)->nickname_is_available())
	{
		delete (*it);
		it++;
	}
	historical.erase(historical.begin(), it);
}

void	Historical::_clear_history	(void)
{
	std::vector<HistoricalNode *> &	historical	= this->_historical;
	HISTORICAL_IT					it			= historical.begin();
	HISTORICAL_IT					ite			= historical.end();

	while (it != ite)
	{
		delete (*it);
		it++;
	}
	historical.clear();
}
