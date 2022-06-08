/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.structor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:13:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/08 15:34:57 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::OPE_TYPE	Data::_ope_list = Data::_init_ope_list();

Data:: Data	(String password
			,String servername
			,String hostname)
	:_password(password)
	,_servername(servername)
	,_hostname(hostname)
{
	std::cout	<< "Data dfl constructor."
				<< std::endl;

				
	time_t	cur_time = time(NULL);
	struct tm * timeinfo;
  	char buffer [80];

  	time (&cur_time);
  	timeinfo = localtime (&cur_time);

	strftime (buffer,80,"%H:%M:%S %b %d %Y",timeinfo);
	this->_created_date = String(buffer);
	//this->_created_date = ctime(&cur_time);
	String::iterator	it = this->_created_date.end() - 1;
	if (*it == '\n')
		this->_created_date.erase(it);
}

Data:: Data	(Data & src)
	:_password(src._password)
	,_servername(src._servername)
	,_hostname(src._hostname)
	,_created_date(src._created_date)
{
	std::cout	<< "Data cpy constructor."
				<< std::endl;
}

Data::~Data	(void)
{
	std::cout	<< "Data destructor."
				<< std::endl;
	this->_delete_users();
	this->_delete_channels();
}

