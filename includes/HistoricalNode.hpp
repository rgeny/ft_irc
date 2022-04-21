/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HistoricalNode.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:33:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 10:59:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORICALNODE_HPP
# define HISTORICALNODE_HPP
# define NICKNAME_DOWNTIME 5

# include <iostream>

class HistoricalNode
{
	public:
		HistoricalNode	(std::string last
						,std::string actual);
		HistoricalNode	(HistoricalNode & src);
		~HistoricalNode	(void);

		HistoricalNode &	operator=	(HistoricalNode & src);

		const std::string &	get_last		(void) const;
		const std::string &	get_actual		(void) const;
		const time_t &		get_timestamp	(void) const;

	private:
		const std::string	_last;
		const std::string	_actual;
		const time_t		_timestamp;

		HistoricalNode	(void);
};

std::ostream &	operator<<	(std::ostream & os
							,HistoricalNode & src);
#endif

