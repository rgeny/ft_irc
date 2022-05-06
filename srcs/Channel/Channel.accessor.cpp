/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.accessor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:37:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/06 12:43:01 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::CHAN_USER_LIST & Channel::get_chan_user_list()
{
    return (_chan_user_list);
}

Channel::CHAN_INVITE_LIST & Channel::get_chan_invite_list()
{
    return (_chan_invite_list);
}

Channel::CHAN_BAN_LIST & Channel::get_chan_ban_list()
{
    return (_chan_ban_list);
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

void	Channel::set_topic_creator(User *creator)
{
    this->_topic_creator = creator;
}

void	Channel::set_topic_creation_time(time_t creation_time)
{
    this->_topic_creation_time = creation_time;
}

User *  Channel::get_topic_creator()
{
    return (_topic_creator);    
}

time_t & Channel::get_topic_creation_time()
{
    return (_topic_creation_time);    
}