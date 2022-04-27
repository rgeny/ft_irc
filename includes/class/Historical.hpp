/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Historical.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:54:36 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:41:19 by rgeny            ###   ########.fr       */
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

		Historical	(void);
		Historical	(Historical & src);
		~Historical	(void);

		Historical &	operator=	(Historical & src);

		void		new_node		(String last
									,String actual);
		String	find_actual		(String nickname);
		bool		nick_is_lock	(String & nickname);

	private:
		std::vector<HistoricalNode *>	_historical;

		void	_rm_obsolete_history	(void);
		void	_clear_history			(void);
};

std::ostream &	operator<<	(std::ostream & os
							,Historical & src);
#endif

