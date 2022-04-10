/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/10 17:44:20 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>

class Client
{
	public:
		Client	(Client & src);
		~Client	(void);

		Client &	operator=	(Client & src);

	private:
		Socket		_socket;
		std::string	_nickname;

		Client	(void);

};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

