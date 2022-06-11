/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:50:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/11 10:15:07 by abesombes        ###   ########.fr       */
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
		typedef std::map<String, std::string>	OPE_TYPE;

		static OPE_TYPE	_ope_list;

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
		std::string	_password;
		String		_servername;
		String		_hostname;
		String		_created_date;
		Historical	_historical;

		User *	_get_user	(String nickname) const;

		size_t	_count_users	(void) const;
		size_t	_count_services	(void) const;
		size_t	_count_operator	(void) const;
		bool	_user_exist	(String nickname) const;
		bool	_chan_exist	(String name) const;

		std::vector<String>	_expand_mask	(String name);
		std::vector<String> _find_chan		(String name);
		

		// Access Control
		Channel::CHAN_USER_LIST *_chan_user_list;
		Channel::CHAN_INVITE_LIST *_chan_invite_list;
		Channel::CHAN_BAN_LIST *_chan_ban_list;
		bool _is_key_set;
		bool _is_limit_set;
		bool _inviteonly_set;
		bool _is_on_ban_list;
		bool _is_on_guestlist;
		bool _is_above_chan_limit;
		String _current_key;
		std::vector<String> _chan_list;
		std::vector<String> _password_list;
		std::vector<String> _nick_list;
		User::CHAN_USERMODE _chan_usermode;

		bool _user_already_in_channel;
		bool _flag_badchanmask;

	private:
		static OPE_TYPE	_init_ope_list	(void);

		void	_delete_users	(void);
		void	_delete_channels	(void);

		void	_fill_vector	(std::vector<String> & expand);
		void	_add_users		(std::vector<String> & expand);
		void	_add_chans		(std::vector<String> & expand);
};

#endif

