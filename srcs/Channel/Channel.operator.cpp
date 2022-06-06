/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:37:42 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/06 17:28:58 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel &	Channel::operator=	(Channel const & src)
{
	this->_name = src._name;
	this->_topic = src._topic;
	this->_topic_creator = src._topic_creator;
	this->_topic_creation_time = src._topic_creation_time;
	this->_chan_user_list = src._chan_user_list;
	this->_chan_invite_list = src._chan_invite_list;
	this->_chan_ban_list = src._chan_ban_list;
	this->_mode = src._mode;
	this->_password = src._password;
	this->_limit = src._limit;
	this->_creation = src._creation;
	this->_is_safe = src._is_safe;
	this->_reop_delay = src._reop_delay;
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,Channel & src)
{
	(void)src;
	return (os);
}

