/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/14 10:50:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP
# include "Socket.hpp"
# include "Accessor.hpp"
# include <iostream>
# include <map>

class Client
{
	public:
		Client	(std::string nickname);
		Client	(Client & src);
		~Client	(void);

		Client &	operator=	(Client & src);

		Accessor<std::string>	nickname;
		Socket &	get_socket(void);
		
	private:
		Socket	_socket;
		Client	(void);

};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

