/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Historical.member.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:05:09 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 12:07:56 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Historical.hpp"

void	Historical::new_node	(std::string last
								,std::string actual)
{
	this->_rm_obsolete_history();
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

void	Historical::_rm_obsolete_history	(void)
{
	std::vector<HistoricalNode *> &	historical	= this->_historical;
	HISTORICAL_IT					it			= historical.begin();
	HISTORICAL_IT					ite			= historical.end();
	time_t							cur_time	= time(NULL);

	while (it != ite
			&& (*it)->nickname_is_available())
	{
		delete (*it);
		historical.erase(it);
		it++;
	}
}
