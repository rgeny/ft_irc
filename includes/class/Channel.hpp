/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:14:15 by ayzapata          #+#    #+#             */
/*   Updated: 2022/05/04 18:44:35 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "User.hpp"

typedef enum
{
	CHANMODE_a,
	CHANMODE_i,
	CHANMODE_m,
	CHANMODE_n,
	CHANMODE_q,
	CHANMODE_p,
	CHANMODE_s,
	CHANMODE_r,
	CHANMODE_t,
	CHANMODE_k,
	CHANMODE_l,
	CHANMODE_b,
	CHANMODE_e,
	CHANMODE_I,	
	
}	ChanMode;

        // O - give "channel creator" status;
        // o - give/take channel operator privilege;
        // v - give/take the voice privilege;

        // a - toggle the anonymous channel flag;
        // i - toggle the invite-only channel flag;
        // m - toggle the moderated channel;
        // n - toggle the no messages to channel from clients on the
        //     outside;
        // q - toggle the quiet channel flag;
        // p - toggle the private channel flag;
        // s - toggle the secret channel flag;
        // r - toggle the server reop channel flag;
        // t - toggle the topic settable by channel operator only flag;

        // k - set/remove the channel key (password);
        // l - set/remove the user limit to channel;

        // b - set/remove ban mask to keep users out;
        // e - set/remove an exception mask to override a ban mask;
        // I - set/remove an invitation mask to automatically override
        //     the invite-only flag;

class Channel
{
	public:
		typedef std::map<String, User *>	CHAN_USER_LIST;
		typedef std::vector<bool>			MODE_VEC;

	private:
		Channel();
		String 				_name;
		String				_topic;
		CHAN_USER_LIST		_chan_user_list;
		MODE_VEC			_mode;
		String				_password;
		size_t				_limit;
		time_t				_creation;
		bool				_is_safe;
		int					_reop_delay;

	
	public:
		Channel(String &name,
				String password);
		// Channel(String const &	name,
		// 		String const & tocomgit spic,
		// 		std::vector<bool> const & mode,
		// 		String const & password,
		// 		std::size_t const & limit,
		// 		bool		const & is_safe,
		// 		int			const &	reop_delay
		// 		);
		Channel( Channel const & src);
		Channel & operator=(Channel const & rhs);
		~Channel();
		CHAN_USER_LIST & get_chan_user_list();
		std::string& get_chan_name();
		String &get_topic();
		time_t 	get_creation() const;
		bool 	chan_exist(String) const;
		void	set_topic(String topic);
		bool 	has_topic();
		void	set_specific_mode (ChanMode mode, bool val);
		void	set_specific_mode (size_t mode, bool val);
		bool	get_specific_mode	(ChanMode mode) const;
		bool	get_specific_mode	(size_t mode) const;
		MODE_VEC get_mode() const;
		String	get_mode_string(void);


		// bool user_exist_in_chan(String nickname) const;

};

std::ostream&	operator<<( std::ostream& o, Channel const & instance);

#endif
