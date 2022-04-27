/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:06:36 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 12:07:59 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

unsigned char	String::_cast	(char c) const
{
	return (String::_case_off[static_cast<unsigned char>(c)]);
}
