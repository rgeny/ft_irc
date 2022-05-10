/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:09:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 18:31:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void	Data::_add_chans	(std::vector<String> & expand)
{
	CHANS_IT	it	= this->_chans.begin(),
				ite	= this->_chans.end();
	
	while (it != ite)
	{
		expand.push_back((*it).second->get_chan_name());
		it++;
	}
}

void	Data::_add_users	(std::vector<String> & expand)
{
	USERS_IT	it	= this->_users.begin(),
				ite	= this->_users.end();
	
	while (it != ite)
	{
		expand.push_back((*it)->get_nickname());
		it++;
	}
}

void	Data::_fill_vector	(std::vector<String> & expand)
{
	this->_add_chans(expand);
	this->_add_users(expand);
	expand.push_back(this->_servername);
}

std::vector<String>	Data::_expand_mask	(String name)
{
	std::vector<String>	expand;
	this->_fill_vector(expand);

	for (std::vector<String>::iterator it = expand.begin(), ite = expand.end(); it != ite; it++)
	{
		if (name != *it)
			expand.erase(it);
	}

	return (expand);
}

std::vector<String> Data::_find_chan	(String name)
{
	std::vector<String>	expand;
	this->_add_chans(expand);

	for (std::vector<String>::iterator it = expand.begin(), ite = expand.end(); it != ite; it++)
	{
		if (name != *it)
			expand.erase(it);
	}

	return (expand);

}
