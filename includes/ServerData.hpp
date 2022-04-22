/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:55:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 01:38:58 by rgeny            ###   ########.fr       */
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
		std::vector<User *>		_users;
		std::string				_servername;
		std::string				_hostname;
		std::string				_password;
		Historical				_historical;
};

#endif

