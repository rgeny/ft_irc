/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:45:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 23:48:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client:: Client	(void)
	:Socket()
	,be_disconnected(false)
	,_nickname(DFL_NICKNAME)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(false)
{
	std::cout	<< "Client dfl constructor."
				<< std::endl;
}

Client:: Client	(String nickname)
	:Socket()
	,be_disconnected(false)
	,_nickname(nickname)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(false)
{
	std::cout	<< "Client parameter constructor."
				<< std::endl;
}

Client:: Client	(Client & src)
	:Socket()
	,be_disconnected(src.be_disconnected)
	,_nickname(src._nickname)
	,_msg_queue(src._msg_queue)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(src._passwd_is_sent)
{
	std::cout	<< "Client cpy constructor."
				<< std::endl;
}

Client::~Client	(void)
{
	std::cout	<< "Client destructor."
				<< std::endl;
}

