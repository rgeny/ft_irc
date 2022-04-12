/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:30:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/12 12:56:19 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP
#include <iostream>
#include <string>
#include <vector>
#include "User.hpp"
#include "Accessor.hpp"
#include "Socket.hpp"
#include "ircserv.hpp"

class Command
{
	public:
		Command	(void);
		Command	(Command & src);
		~Command	(void);
		void parse(std::string cmd_str, Socket *user);

		Command &	operator=	(Command & src);

	private:
		std::vector<std::string> _cmd;
		Socket *_user;
};

std::ostream &	operator<<	(std::ostream & os
							,Command & src);
#endif

