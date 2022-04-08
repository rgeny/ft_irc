/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:45:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/08 12:45:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client:: Client	(void)
{
	std::cout	<< "Client dfl constructor."
				<< std::endl;
}

Client:: Client	(Client & src)
{
	(void)src;
	std::cout	<< "Client cpy constructor."
				<< std::endl;
}

Client::~Client	(void)
{
	std::cout	<< "Client destructor."
				<< std::endl;
}

