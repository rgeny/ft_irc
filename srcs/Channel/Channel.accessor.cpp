/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.accessor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:37:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/16 22:06:06 by abesombe         ###   ########.fr       */
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

String Channel::get_name_list(int access_level)
{
    CHAN_USER_LIST *chan_ulist = NULL;
    String name_list;

    chan_ulist = &this->get_chan_user_list();
    for (CHAN_USER_LIST::iterator it = chan_ulist->begin(); it != chan_ulist->end(); it++)
    {
        // if requesting user is not member of the channel && if the chan_user is in invisible mode, 
        // chan_user should not appear in the list.
        User* cur_user = (*it).second;
        String chan_name = this->get_chan_name();
        bool is_invisible = cur_user->get_specific_mode(USERMODE_i) ;
        
        if (access_level || !is_invisible)
        {
            if (it != chan_ulist->begin())
                name_list += " ";
            if ((*it).second->get_chan_usermode_vec(this->get_chan_name())[USERMODE_o] == true)
                name_list += "@";
            name_list += (*it).second->get_nickname();
        }
    }
    return (name_list);
}

std::vector<User*> Channel::get_raw_nick_list(int access_level)
{
    CHAN_USER_LIST *chan_ulist = NULL;
    std::vector<User*> name_list;

    chan_ulist = &this->get_chan_user_list();
    for (CHAN_USER_LIST::iterator it = chan_ulist->begin(); it != chan_ulist->end(); it++)
    {
        // if requesting user is not member of the channel && if the chan_user is in invisible mode, 
        // chan_user should not appear in the list.
        User* cur_user = (*it).second;
        String chan_name = this->get_chan_name();
        bool is_invisible = cur_user->get_specific_mode(USERMODE_i) ;
        if (access_level || !is_invisible)
        {
            name_list.push_back(cur_user);
        }
    }
    return (name_list);
}