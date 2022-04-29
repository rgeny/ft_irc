/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 04:36:24 by rgeny            ###   ########.fr       */
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
		bool	be_disconnected;

		Client	(void);
		Client	(String nickname);
		Client	(Client & src);
		~Client	(void);

		Client &	operator=	(Client & src);

		const String &	get_nickname	(void) const;
		bool				set_nickname	(String nickname);
		bool				get_passwd_is_sent	(void) const;
		void				set_passwd_is_sent	(bool new_val);

		void	add_to_queue		(String & msg);
		bool	is_empty_msg_queue	(void) const;
		int		receive				(String & msg);
		bool	is_empty_recv_queue	(void) const;
		int		send				(void);

	private:
		String				_nickname;
		std::queue<String>	_recv_queue;
		String				_recv_buf;
		std::queue<String>	_msg_queue;
		time_t				_msg_timer;
		bool				_passwd_is_sent;

		int		_get_next_msg	(String & msg);
};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

