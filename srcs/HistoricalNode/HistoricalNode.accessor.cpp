/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HistoricalNode.accessor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:33:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:39:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HistoricalNode.hpp"

const String &	HistoricalNode::get_last	(void) const
{
	return (this->_last);
}

const String &	HistoricalNode::get_actual	(void) const
{
	return (this->_actual);
}

const time_t &	HistoricalNode::get_timestamp	(void) const
{
	return (this->_timestamp);
}
