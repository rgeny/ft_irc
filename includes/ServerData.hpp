/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:55:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 14:49:31 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERDATA_HPP
# define SERVERDATA_HPP

# include <iostream>
# include <string>
# include <vector>
# include "User.hpp"
# include "Historical.hpp"

struct ServerData
{
	public:
		std::vector<User *>			_users;
		std::map<User *, time_t>	_tmp_users;
		std::string					_servername;
		std::string					_hostname;
		std::string					_password;
		Historical					_historical;
};

#endif

