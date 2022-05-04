/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:57:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 14:57:09 by rgeny            ###   ########.fr       */
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
	return (SEND_ERROR);
}

bool	Client::is_empty_recv_queue	(void) const
{
	return (this->_recv_queue.empty());
}

int		Client::receive	(String & msg)
{
//	Flood control
	time_t		cur_time	= time(NULL);
	time_t &	msg_timer	= this->_msg_timer;
	if ((msg_timer - cur_time) + MSG_PENALIZE_TIME >= MSG_MAX_TIMER)
		return (RECV_ERROR);

//	Get next message send by user
	int	ret = this->_get_next_msg(msg);
	if (ret == RECV_ERROR)
		return (RECV_ERROR);

//	debug message
	std::cout	<< std::endl
				<< BOLD
				<< "Message parsed : "
				<< RESET
				<< std::endl
				<< "\""
				<< msg
				<< "\""
				<< std::endl;
	
//	Actualize Client message timer for flood controle
	if (msg_timer < cur_time)
		msg_timer = cur_time;
	msg_timer += MSG_PENALIZE_TIME;
	this->_t_last_msg = cur_time;

	return (ret);
}

int		Client::_get_next_msg	(String & msg)
{
	int	ret = 0;

	if (this->_recv_queue.empty())
	{
		ret	= this->Socket::receive(this->_recv_buf);
		size_t	end_of_msg	= this->_recv_buf.rfind(END_OF_MSG);

		if (end_of_msg == String::npos)
		{
			// tmp
			if (this->_recv_buf.size() >= BUF_SIZE)
				this->_recv_buf.clear();
			// fin tmp
			return (RECV_ERROR);
		}

		this->_recv_queue = qsplit(this->_recv_buf.substr(0, end_of_msg), END_OF_MSG);
		this->_recv_buf.erase(0, end_of_msg + strlen(END_OF_MSG));
	}
	if (this->_recv_queue.empty())
		return (RECV_ERROR);
	msg = this->_recv_queue.front();
	this->_recv_queue.pop();
	if (ret == 0)
		return (msg.size());
	return (ret);
}
