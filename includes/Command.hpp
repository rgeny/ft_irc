/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:30:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/13 11:45:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "User.hpp"
#include "Accessor.hpp"
#include "Client.hpp"
#include "ircserv.hpp"

class Command
{
	public:
		Command	(void);
		// Command	(std::vector<std::string> const & cmd);
		Command	(Command & src);
		~Command	(void);
		void parse(std::string cmd_str, Client * user);
		Command &	operator=	(Command & src);
		Accessor<std::vector<std::string> > cmd;
		
	private:
		Client *_user;
};

std::ostream &	operator<<	(std::ostream & os
							,Command & src);
#endif

