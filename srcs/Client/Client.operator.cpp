/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:55:22 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 09:50:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client &	Client::operator=	(Client & src)
{
	this->_nickname = src._nickname;
	return (*this);
}

std::ostream &	operator<<		(std::ostream & os
								,Client & src)
{
	os	<< src.get_nickname();
	return (os);
}

