/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:50:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 16:12:03 by rgeny            ###   ########.fr       */
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
# include "Historical.hpp"

class Data
{
	public:
		typedef std::vector<User *>						USERS_LIST;
		typedef USERS_LIST::iterator					USERS_IT;
		typedef std::map<User *, time_t>				TMP_USERS;
		typedef TMP_USERS::iterator						TMP_USERS_IT;
		typedef std::vector<std::vector<std::string> >	MSGS_LIST;
		typedef MSGS_LIST::iterator						MSGS_IT;

		Data	(std::string password = DFL_PASSWD
				,std::string servername = DFL_SERVERNAME
				,std::string hostname = DFL_HOSTNAME);
		Data	(Data & src);
		~Data	(void);

		Data &	operator=	(Data & src);

	protected:
		USERS_LIST		_users;
		USERS_IT		_users_it;
		USERS_IT		_users_ite;

		TMP_USERS		_tmp_users;
//		TMP_USERS_IT	_tmp_users_it;
//		TMP_USERS_IT	_tmp_users_ite;

		std::string		_msg;
		MSGS_LIST		_msgs;
		MSGS_IT			_msgs_it;
		MSGS_IT			_msgs_ite;

		std::string		_servername;
		std::string		_password;
		std::string		_hostname;
		Historical		_historical;

		void	_delete_users	(void);
};

#endif

