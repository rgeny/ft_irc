/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.accessor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:09 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/15 17:42:31 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

std::string Message::getSender() const
{
	return (this->_sender);
}

std::string Message::getReceiver() const
{
	return (this->_receiver);
}

void	Message::setSender(std::string &sender)
{
	this->_sender = sender;
}

void	Message::setReceiver(std::string &receiver)
{
	this->_receiver = receiver;
}
