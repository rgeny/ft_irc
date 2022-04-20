/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:57:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/20 19:33:04 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

void	Client::add_to_queue	(std::string & msg)
{
	this->_msg_queue.push(msg);
}

bool	Client::is_empty_msg_queue	(void) const
{
	return (this->_msg_queue.empty());
}

int		Client::send	(void)
{
	if (this->_msg_queue.empty())
		std::cout	<< "Queue is empty, clients can't send a msg."
					<< std::endl;
	else
	{
		std::string &	msg = this->_msg_queue.front();
		this->_msg_queue.pop();
		return (this->Socket::send(msg));
	}
	return (-1);
}

int		Client::receive	(std::string & msg)
{
	time_t		cur_time	= time(NULL);
	time_t &	msg_timer	= this->_msg_timer;

	if (msg_timer < cur_time)
		msg_timer = cur_time;
	else if ((msg_timer - cur_time) > MSG_MAX_TIMER)
		return (-1);
	msg_timer += MSG_PENALIZE_TIME;
	return (this->Socket::receive(msg));
}
