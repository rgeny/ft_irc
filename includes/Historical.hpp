/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Historical.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:54:36 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 12:08:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORICAL_HPP
# define HISTORICAL_HPP
# define NICKNAME_DOWNTIME 5

# include <iostream>
# include <vector>
# include "HistoricalNode.hpp"

class Historical
{
	public:
		typedef std::vector<HistoricalNode *>::iterator			HISTORICAL_IT;
		typedef std::vector<HistoricalNode *>::reverse_iterator	HISTORICAL_RIT;
		Historical	(void);
		Historical	(Historical & src);
		~Historical	(void);

		Historical &	operator=	(Historical & src);

		void		new_node	(std::string last
								,std::string actual);
		std::string	find_actual	(std::string nickname);

	private:
		std::vector<HistoricalNode *>	_historical;

		void	_rm_obsolete_history	(void);
};

std::ostream &	operator<<	(std::ostream & os
							,Historical & src);
#endif

