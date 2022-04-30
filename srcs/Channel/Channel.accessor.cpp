/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.accessor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:37:04 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/30 20:34:50 by ayzapata         ###   ########.fr       */
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

void	Channel::set_topic(String topic)
{
    this->_topic = topic;
}

String & Channel::get_topic()
{
    return (_topic);    
}

