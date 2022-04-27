/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:50:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:26:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# define DFL_HOSTNAME "127.0.0.1"
# define DFL_SERVERNAME "MajinBoo"
# define DFL_PASSWD "dnquejfjzeisfjeifj"

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
		typedef std::vector<String>				MSG;
		typedef std::vector<MSG>				MSGS_LIST;
		typedef MSGS_LIST::iterator				MSGS_IT;

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
//		TMP_USERS_IT	_tmp_users_it;
//		TMP_USERS_IT	_tmp_users_ite;

		// Client message being processed
		String		_msg;
		MSGS_LIST	_msgs;
		MSGS_IT		_msgs_it;
		MSGS_IT		_msgs_ite;

		// Server data
		String		_password;
		String		_servername;
		String		_hostname;
		Historical		_historical;

		void	_delete_users	(void);
};

#endif

