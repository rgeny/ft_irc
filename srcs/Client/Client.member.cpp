/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:57:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:35:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

void	Client::add_to_queue	(String & msg)
{
	if (!this->be_disconnected)
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
		String &	msg = this->_msg_queue.front();
		int	ret = this->Socket::send(msg);
		this->_msg_queue.pop();
		return (ret);
	}
	return (-1);
}

int		Client::receive	(String & msg)
{
	time_t		cur_time	= time(NULL);
	time_t &	msg_timer	= this->_msg_timer;

	if (msg_timer < cur_time)
		msg_timer = cur_time;
	if ((msg_timer - cur_time) + MSG_PENALIZE_TIME >= MSG_MAX_TIMER)
		return (-1);
	msg_timer += MSG_PENALIZE_TIME;
	return (this->Socket::receive(msg));
}
