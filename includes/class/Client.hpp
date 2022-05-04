/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/04 20:54:58 by rgeny            ###   ########.fr       */
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

enum timeout
{
	TIMEOUT_CO,
	TIMEOUT_PING
};

class Client
	:public Socket
{
	public:
		Client	(void);
		Client	(String nickname);
		Client	(Client & src);
		~Client	(void);

		Client &	operator=	(Client & src);

		const String &	get_nickname	(void) const;
		bool				set_nickname	(String nickname);
		bool				get_passwd_is_sent	(void) const;
		void				set_passwd_is_sent	(bool new_val);
		time_t				get_t_last_msg	(void) const;

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
		time_t				_t_last_msg;

		int		_get_next_msg	(String & msg);

	public:
		timeout				reason;
};

std::ostream &	operator<<	(std::ostream & os
							,Client & src);
#endif

