/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/12 15:33:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP
# define DFL_NICKNAME "anonymous"

# include <iostream>
# include "Socket.hpp"

class Client
{
	public:
		Client	(void);
		Client	(std::string nickname);
		Client	(Client & src);
		~Client	(void);

		Client &	operator=	(Client & src);

		const std::string &	get_nickname	(void) const;
		void				set_nickname	(std::string nickname);

	private:
		Socket		_socket;
		std::string	_nickname;
};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

