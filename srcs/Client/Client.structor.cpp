/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:45:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 20:55:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client:: Client	(void)
	:Socket()
	,_nickname(DFL_NICKNAME)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(false)
	,_t_last_msg(time(NULL))
	,reason(TIMEOUT_CO)
{
	std::cout	<< "Client dfl constructor."
				<< std::endl;
}

Client:: Client	(String nickname)
	:Socket()
	,_nickname(nickname)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(false)
	,_t_last_msg(time(NULL))
	,reason(TIMEOUT_CO)
{
	std::cout	<< "Client parameter constructor."
				<< std::endl;
}

Client:: Client	(Client & src)
	:Socket()
	,_nickname(src._nickname)
	,_msg_queue(src._msg_queue)
	,_msg_timer(time(NULL))
	,_passwd_is_sent(src._passwd_is_sent)
	,_t_last_msg(time(NULL))
	,reason(src.reason)
{
	std::cout	<< "Client cpy constructor."
				<< std::endl;
}

Client::~Client	(void)
{
	std::cout	<< "Client destructor."
				<< std::endl;
}

