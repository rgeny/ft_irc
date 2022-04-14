/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/14 15:19:25 by abesombe         ###   ########.fr       */
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
		User &		get_user(void);
		
	private:
		Socket	_socket;
		User	_user;
		Client	(void);

};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

