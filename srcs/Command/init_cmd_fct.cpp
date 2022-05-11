/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_fct.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:48:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/11 15:41:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::_init_cmd_fct	(void)
{
	if (Command::_cmds_fct.size() == 0)
	{
		Command::_cmds_fct[INFO]		= &Command::_info;
		Command::_cmds_fct[INVITE]		= &Command::_invite;
		Command::_cmds_fct[JOIN]		= &Command::_join;
		Command::_cmds_fct[KICK]		= &Command::_kick;
		Command::_cmds_fct[MODE]		= &Command::_mode;
		Command::_cmds_fct[MOTD]		= &Command::_motd;
		Command::_cmds_fct[NICK]		= &Command::_nick;
		Command::_cmds_fct[NOTICE]		= &Command::_notice;
		Command::_cmds_fct[PART]		= &Command::_part;
		Command::_cmds_fct[PASS]		= &Command::_pass;
		Command::_cmds_fct[PING]		= &Command::_ping;
		Command::_cmds_fct[PRIVMSG]		= &Command::_privmsg;
		Command::_cmds_fct[QUIT]		= &Command::_quit;
		Command::_cmds_fct[TIME]		= &Command::_time;
		Command::_cmds_fct[TOPIC]		= &Command::_topic;
		Command::_cmds_fct[USER]		= &Command::_user;
		Command::_cmds_fct[USERHOST]	= &Command::_userhost;
		Command::_cmds_fct[PONG]		= &Command::_pong;
		Command::_cmds_fct[LIST]		= &Command::_list;
		Command::_cmds_fct[LUSERS]		= &Command::_lusers;
		Command::_cmds_fct[OPER]		= &Command::_oper;
	}
}

