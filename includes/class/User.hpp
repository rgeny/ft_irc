/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:04:52 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/29 16:37:44 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP
# define DFL_USERNAME "anonymous"
# define DFL_REALNAME "anonymous"

# include <iostream>
# include <string>
# include <vector>
# include <map>
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
	USERMODE_s,
	USERMODE_v,
}	UserMode;

/*

        O - give "channel creator" status;
        o - give/take channel operator privilege;
        v - give/take the voice privilege;

        a - toggle the anonymous channel flag;
        i - toggle the invite-only channel flag;
        m - toggle the moderated channel;
        n - toggle the no messages to channel from clients on the
            outside;
        q - toggle the quiet channel flag;
        p - toggle the private channel flag;
        s - toggle the secret channel flag;
        r - toggle the server reop channel flag;
        t - toggle the topic settable by channel operator only flag;

        k - set/remove the channel key (password);
        l - set/remove the user limit to channel;

        b - set/remove ban mask to keep users out;
        e - set/remove an exception mask to override a ban mask;
        I - set/remove an invitation mask to automatically override
            the invite-only flag;
*/

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
		void	set_chan_usermode	(String chan_name
									,int mode);
		void	set_realname		(String realname);

		bool	co_is_complete	(void) const;

	private:
		String									_username;
		std::vector<bool>						_mode;
		String									_realname;
		std::map<String, std::vector<bool> >	_chan_usermode;
};

std::ostream &	operator<<	(std::ostream & os
							,User & src);
#endif

