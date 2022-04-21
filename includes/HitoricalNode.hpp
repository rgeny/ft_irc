/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HitoricalNode.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:28:42 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 10:33:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITORICALNODE_HPP
# define HITORICALNODE_HPP
# include <iostream>

class HitoricalNode
{
	public:
		HitoricalNode	(std::string last_nickname
						,std::string new_nickname);
		~HitoricalNode	(void);

		HitoricalNode &	operator=	(HitoricalNode & src);

	private:
		const std::string	_last_nickname;
		const std::string	_new_nickname;
		const time_t		_timestamp;

		HitoricalNode	(void);
		HitoricalNode	(HitoricalNode & src);
};

#endif

