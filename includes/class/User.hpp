/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:04:52 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/28 00:06:05 by rgeny            ###   ########.fr       */
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
# include "String.hpp"

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
		User	(String	nickname
				,String	username
				,String	mode
				,String	realname);
		User	(User const & src);
		~User	(void);

		User &	operator=	(User & src);

		const String				get_username		(void) const;
		const std::vector<bool>		get_mode			(void) const;
		bool						get_specific_mode	(UserMode mode) const;
		const String				get_realname		(void) const;

		void	set_username		(String username);
		void	set_mode			(String mode);
		void	set_specific_mode	(UserMode mode
									,bool val);
		void	set_realname		(String realname);

		bool	co_is_complete	(void) const;

	private:
		String			_username;
		std::vector<bool>	_mode;
		String			_realname;
};

std::ostream &	operator<<	(std::ostream & os
							,User & src);
#endif

