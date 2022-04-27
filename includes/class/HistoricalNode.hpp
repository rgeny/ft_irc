/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HistoricalNode.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:33:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 21:08:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORICALNODE_HPP
# define HISTORICALNODE_HPP
# define NICKNAME_DOWNTIME 5

# include <iostream>

# include "String.hpp"

class HistoricalNode
{
	public:
		HistoricalNode	(String last
						,String actual);
		HistoricalNode	(HistoricalNode & src);
		~HistoricalNode	(void);

		HistoricalNode &	operator=	(HistoricalNode & src);

		const String &	get_last		(void) const;
		const String &	get_actual		(void) const;
		const time_t &		get_timestamp	(void) const;

		bool		nickname_is_available	(void) const;

	private:
		const String	_last;
		const String	_actual;
		const time_t		_timestamp;

		HistoricalNode	(void);
};

std::ostream &	operator<<	(std::ostream & os
							,HistoricalNode & src);
#endif

