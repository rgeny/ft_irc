/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:57:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/18 22:16:36 by rgeny            ###   ########.fr       */
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
