/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.accessor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:37:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/05 21:09:38 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::CHAN_USER_LIST & Channel::get_chan_user_list()
{
    return (_chan_user_list);
}

std::string& Channel::get_chan_name()
{
    return (_name);
}

time_t Channel::get_creation() const
{
    return (_creation);
}

Channel::MODE_VEC Channel::get_mode() const
{
    return (_mode);
}

void	Channel::set_topic(String topic)
{
    this->_topic = topic;
}

String & Channel::get_topic()
{
    return (_topic);    
}

void	Channel::set_key(String key)
{
    this->_password = key;
}

String & Channel::get_key()
{
    return (_password);    
}

void	Channel::set_limit(String limit)
{
    this->_limit = strtol(limit.c_str(), NULL, 10);
}


void	Channel::set_limit(size_t limit)
{
    this->_limit = limit;
}

size_t& Channel::get_limit()
{
    return (_limit);
}

void	Channel::set_specific_mode		(ChanMode mode
									    ,bool val)
{
	this->_mode[mode] = val;
}

void	Channel::set_specific_mode		(size_t mode
									    ,bool val)
{
	this->_mode[mode] = val;
}

bool	Channel::get_specific_mode	(ChanMode mode) const
{
	return (this->_mode[mode]);
}

bool	Channel::get_specific_mode	(size_t mode) const
{
	return (this->_mode[mode]);
}
