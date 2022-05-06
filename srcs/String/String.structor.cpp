/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:00:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 19:17:14 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

std::vector<unsigned char>  String::_case_off = String::_init_case_off();

String:: String	(void)
	:std::string()
{
//	std::cout	<< "String dfl constructor."
//				<< std::endl;
//	this->_init_case_off();
}

String:: String	(const String & src)
	:std::string(src)
{
//	std::cout	<< "String cpy constructor."
//				<< std::endl;
//	this->_init_case_off();
}

String:: String	(const String & str
				,size_t pos
				,size_t len)
	:std::string(str, pos, len)
{
//	std::cout	<< "String substring constructor."
//				<< std::endl;
//	this->_init_case_off();
}

String:: String	(const std::string & str)
	:std::string(str)
{
//	std::cout	<< "String from std::string constructor."
//				<< std::endl;
//	this->_init_case_off();
}

String:: String	(const char * s)
	:std::string(s)
{
//	std::cout	<< "String from c-string constructor."
//				<< std::endl;
//	this->_init_case_off();
}

String:: String	(const char * s
				,size_t n)
	:std::string(s, n)
{
//	std::cout	<< "String from sequence constructor."
//				<< std::endl;
//	this->_init_case_off();
}

String:: String	(size_t n
				,char c)
	:std::string(n, c)
{
//	std::cout	<< "String fill constructor."
//				<< std::endl;
//	this->_init_case_off();
}

String::~String	(void)
{
//	std::cout	<< "String destructor."
//				<< std::endl;
}

