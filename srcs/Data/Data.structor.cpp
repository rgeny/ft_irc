/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.structor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:13:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:36:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data:: Data	(String password
			,String servername
			,String hostname)
	:_password(password)
	,_servername(servername)
	,_hostname(hostname)
{
	std::cout	<< "Data dfl constructor."
				<< std::endl;
}

Data:: Data	(Data & src)
	:_password(src._password)
	,_servername(src._servername)
	,_hostname(src._hostname)
{
	std::cout	<< "Data cpy constructor."
				<< std::endl;
}

Data::~Data	(void)
{
	std::cout	<< "Data destructor."
				<< std::endl;
	this->_delete_users();
}

