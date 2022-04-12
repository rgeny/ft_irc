/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:30:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/12 10:30:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP
# include <iostream>

class Command
{
	public:
		Command	(void);
		Command	(Command & src);
		~Command	(void);

		Command &	operator=	(Command & src);

	private:
};

std::ostream &	operator<<	(std::ostream & os
							,Command & src);
#endif

