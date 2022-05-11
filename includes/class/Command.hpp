/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:13:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 14:35:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP
# define CLOSE "Closing"
# define BADPASSWD "Bad password"

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <climits>

# include "User.hpp"
# include "Message.hpp"
# include "e_error.hpp"

class Command
	:virtual protected Message
{
	public:
		typedef e_error (Command::*CommandPointer)	(void);
		typedef std::map<String, CommandPointer>	CmdsFct;

		Command		(void);
		Command		(Command & src);
		~Command	(void);

		Command &	operator=	(Command & src);

		void	main		(void);
		bool 	user_exist_in_chan(Channel &chan, String nickname) const;
		bool 	is_operator(String nickname, Channel &chan);
		String	concat_last_args(size_t start_index);
		void	leave_all (void);
		int 	join_process(String chan_name);
		int		mode_type(char mode);
		int		apply_mode(String target);

	protected:



//		User Command
		e_error		_pass			(void);
		e_error		_nick			(void);
		e_error		_user			(void);
		e_error		_quit			(void);
		e_error		_lusers			(void);
		e_error		_oper			(void);
	
//		Channel Command
		e_error		_join			(void);
		e_error		_topic			(void);
		e_error		_part			(void);
		e_error		_kick			(void);		
		e_error		_invite			(void);		
		e_error		_list			(void);

//		User/Channel Command
		e_error		_mode			(void);
		e_error		_privmsg		(void);
		e_error		_notice			(void);

//		Other Command
		e_error		_ping			(void);
		e_error		_time			(void);
		e_error		_info			(void);
		e_error		_motd			(void);
		e_error		_userhost		(void);
		e_error		_pong			(void);

	private:
		static CmdsFct		_cmds_fct;

		bool			_is_user;

		bool	_get_user_type		(void);
		void	_parse				(void);
		void	_check_cmd			(void);
		bool	_check_prefix		(void);
		bool	_nick_already_used	(String & nickname) const;
		void	_init_cmd_fct	(void);
};

std::ostream &	operator<<	(std::ostream & os
							,Command & src);
#endif

// e_error		_admin		(void);
// e_error		_away		(void);
// e_error		_cap		(void);
// e_error		_cnotice	(void);
// e_error		_cprivmsg	(void);
// e_error		_connect	(void);
// e_error		_die		(void);
// e_error		_encap		(void);
// e_error		_error		(void);
// e_error		_help		(void);
// e_error		_info		(void);
// e_error		_invite		(void);
// e_error		_ison		(void);
// e_error		_kick		(void);
// e_error		_kill		(void);
// e_error		_knock		(void);
// e_error		_links		(void);
// e_error		_list		(void);
// e_error		_lusers		(void);
// e_error		_mode		(void);
// e_error		_motd		(void);
// e_error		_names		(void);
// e_error		_namesx		(void);
// e_error		_notice		(void);
// e_error		_oper		(void);
// e_error		_part		(void);
// e_error		_privmsg	(void);
// e_error		_rehash		(void);
// e_error		_rules		(void);
// e_error		_server		(void);
// e_error		_service	(void);
// e_error		_servlist	(void);
// e_error		_squery		(void);
// e_error		_squit		(void);
// e_error		_setname	(void);
// e_error		_silence	(void);
// e_error		_stats		(void);
// e_error		_summon		(void);
// e_error		_time		(void);
// e_error		_topic		(void);
// e_error		_trace		(void);
// e_error		_uhnames	(void);
// e_error		_userhost	(void);
// e_error		_userip		(void);
// e_error		_users		(void);
// e_error		_version	(void);
// e_error		_wallops	(void);
// e_error		_watch		(void);
// e_error		_who		(void);
// e_error		_whois		(void);
