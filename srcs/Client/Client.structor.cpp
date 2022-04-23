/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:45:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 17:45:47 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client:: Client	(void)
	:_nickname(DFL_NICKNAME)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(false)
	,be_disconnected(false)
{
	std::cout	<< "Client dfl constructor."
				<< std::endl;
}

Client:: Client	(std::string nickname)
	:_nickname(nickname)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(false)
	,be_disconnected(false)
{
	std::cout	<< "Client parameter constructor."
				<< std::endl;
}

Client:: Client	(Client & src)
	:_nickname(src.get_nickname())
	,_msg_timer(time(NULL))
	,_passwd_is_sent(src._passwd_is_sent)
	,be_disconnected(src.be_disconnected)
{
	std::cout	<< "Client cpy constructor."
				<< std::endl;
}

Client::~Client	(void)
{
	std::cout	<< "Client destructor."
				<< std::endl;
}

