/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/18 22:14:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP
# define DFL_NICKNAME "anonymous"

# include <iostream>
# include <queue>
# include "Socket.hpp"
# include "Utils.hpp"

class Client
	:public Socket
{
	public:
		Client	(void);
		Client	(std::string nickname);
		Client	(Client & src);
		~Client	(void);

		Client &	operator=	(Client & src);

		const std::string &	get_nickname	(void) const;
		void				set_nickname	(std::string nickname);

		void	add_to_queue		(std::string & msg);
		bool	is_empty_msg_queue	(void) const;
		int		send				(void);

	private:
//		Socket					_socket;
		std::string				_nickname;
		std::queue<std::string>	_msg_queue;
};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

