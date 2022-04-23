/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 15:18:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP
# define DFL_NICKNAME "anonymous"
# define MSG_MAX_TIMER 10
# define MSG_PENALIZE_TIME 2

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
		bool				set_nickname	(std::string nickname);
		bool				get_passwd_is_sent	(void) const;
		void				set_passwd_is_sent	(bool new_val);

		void	add_to_queue		(std::string & msg);
		bool	is_empty_msg_queue	(void) const;
		int		receive				(std::string & msg);
		int		send				(void);

	private:
		std::string				_nickname;
		std::queue<std::string>	_msg_queue;
		time_t					_msg_timer;
		bool					_passwd_is_sent;
};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

