/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:09:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 22:22:33 by rgeny            ###   ########.fr       */
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

bool	Data::_is_valid_name	(String::iterator & it_word
								,String::iterator & ite_word
								,String::iterator & it_dir
								,String::iterator & ite_dir
								,size_t & i
								,bool escape)
{
	size_t	j = 0;

	while ((it_word + i + j) != ite_word
			&& ((*(it_word + i + j) != '*'
				&& *(it_word + i + j) != '?'
				&& *(it_word + i + j) != '\\')
			|| escape))
	{
		if (*(it_word + i + j) != *(it_dir + i + j))
			return (false);
		j++;
	}
	if (*(it_word + i + j) == '*'
		|| *(it_word + i + j) == '?'
		|| *(it_word + i + j) == '\\'
		|| ((it_word + i + j) == ite_word
			&& (it_dir + i + j) == ite_dir))
	{
		i += j;
		return (true);
	}
	return (false);
}

bool	Data::_expand_cmp	(String & word
							,String & dir)
{
	String::iterator	it_word	= word.begin(),
						ite_word = word.end(),
						it_dir = dir.begin(),
						ite_dir = dir.end();
	size_t				i = 0;
	bool				asterisk = false;
	bool				escape = false;

	while ((it_word + i) != ite_word
			|| (it_dir + i) != ite_dir)
	{
		if (*(it_word + i) == '\\' && (it_word + i + 1) != ite_word)
		{
			escape = true;
			it_word++;
		}
		else if (!escape && *(it_word + i) == '?')
		{
			if ((it_dir + i) != ite_dir)
				it_dir++;
			it_word++;
		}
		else if (!escape && *(it_word + i) == '*')
		{
			while (*(it_word + i) == '*' && (it_word + i) != ite_word)
				it_word++;
			asterisk = true;
		}
		else if (asterisk == true)
		{
			while ((it_dir + i) != ite_dir
					&& !this->_is_valid_name(it_word, ite_word, it_dir, ite_dir, i, escape))
			{
				it_dir++;
			}
			asterisk = false;
			escape = false;
		}
		else
		{
			if (!this->_is_valid_name(it_word, ite_word, it_dir, ite_dir, i, escape))
				return (false);
			escape = false;
		}
	}
	return ((it_word + i) == ite_word
			&& (it_dir + i) == ite_dir);
}

std::vector<String>	Data::_expand_mask	(String name)
{
	(void)name;
	std::vector<String>	expand;
	this->_fill_vector(expand);

	for (std::vector<String>::iterator it = expand.begin(), ite = expand.end(); it != ite; it++)
	{
		if (!this->_expand_cmp(name, *it))
			expand.erase(it);
	}

	return (expand);
}
