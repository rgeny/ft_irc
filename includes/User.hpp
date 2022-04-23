/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:04:52 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/23 14:38:15 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP
# define DFL_USERNAME "anonymous"
# define DFL_REALNAME "anonymous"

# include <iostream>
# include <string>
# include <vector>
# include "Client.hpp"

typedef enum
{
	USERMODE_a,
	USERMODE_i,
	USERMODE_w,
	USERMODE_r,
	USERMODE_o,
	USERMODE_O,
	USERMODE_s
}	UserMode;

class User
	:public Client
{
	public:
		User	(void);
		User	(std::string	nickname
				,std::string	username
				,std::string	mode
				,std::string	realname);
		User	(User & src);
		~User	(void);

		User &	operator=	(User & src);

		const std::string		get_username		(void) const;
		const std::vector<bool>	get_mode			(void) const;
		bool					get_specific_mode	(UserMode mode) const;
		const std::string		get_realname		(void) const;

		void	set_username		(std::string username);
		void	set_mode			(std::string mode);
		void	set_specific_mode	(UserMode mode
									,bool val);
		void	set_realname		(std::string realname);

		bool	co_is_complete	(void) const;

	private:
		std::string			_username;
		std::vector<bool>	_mode;
		std::string			_realname;
};

std::ostream &	operator<<	(std::ostream & os
							,User & src);
#endif

