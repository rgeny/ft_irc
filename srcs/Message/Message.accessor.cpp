/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.accessor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:09 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/15 16:55:25 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

User *	Message::getSender() const
{
	return (this->_sender);
}

User *	Message::getReceiver() const
{
	return (this->_receiver);
}

void	Message::setSender(User * sender)
{
	this->_sender = sender;
}

void	Message::setReceiver(User * receiver)
{
	this->_receiver = receiver;
}
