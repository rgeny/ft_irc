/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:50:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/05 14:21:20 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# define DFL_HOSTNAME "127.0.0.1"
# define DFL_SERVERNAME "MajinBoo"
# define DFL_PASSWD "w8dfrgz4htjydwW48W4WWd4dw"
# define SERVER_VER "0210"
# define USER_MODE "iswo"
# define CHANNEL_MODE "opsitnmlbvk"

# include <ctime>
# include <iostream>
# include <string>
# include <vector>
# include <map>

# include "User.hpp"
# include "Channel.hpp"
# include "Historical.hpp"
# include "String.hpp"

class Data
{
	public:
		typedef std::vector<User *>				USERS_LIST;
		typedef USERS_LIST::iterator			USERS_IT;
		typedef std::map<String, Channel *>		CHANS_LIST;
		typedef CHANS_LIST::iterator			CHANS_IT;
		typedef std::map<User *, time_t>		TMP_USERS;
		typedef TMP_USERS::iterator				TMP_USERS_IT;
		typedef std::vector<String>				CMD;

		Data	(String password = DFL_PASSWD
				,String servername = DFL_SERVERNAME
				,String hostname = DFL_HOSTNAME);
		Data	(Data & src);
		~Data	(void);

		Data &	operator=	(Data & src);

	protected:
		// user list
		USERS_LIST		_users;
		USERS_IT		_users_it;
		USERS_IT		_users_ite;

		// chan list
		CHANS_LIST		_chans;
		CHANS_IT		_chans_it;
		CHANS_IT		_chans_ite;		

		// list of users who must send specific data and will be disconnected if they don't
		TMP_USERS		_tmp_users;

		// Client message being processed
		String		_msg;
		CMD			_cmd;

		// Server data
		String		_password;
		String		_servername;
		String		_hostname;
		String		_created_date;
		Historical	_historical;

		User *	_get_user	(String nickname) const;

		bool	_user_exist	(String nickname) const;
		bool	_chan_exist	(String name) const;

	private:
		void	_delete_users	(void);
		void	_delete_channels	(void);
};

#endif

