/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 22:42:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::parse	(std::string cmd_str
						,Client * user)
{
	std::string	tmp;
	this->tokens = split (cmd_str, " ");
	this->_user = user;
}

void	Command::check_cmd	(Client &sender
							,std::vector<std::string> cmd)
{
	UserCmds::iterator it = _cmd_list.find(case_proof(cmd[0]));
	if (it != _cmd_list.end())
		(this->*(it->second))(sender, cmd);
}

int		Command::nick	(Client & sender
						,std::vector<std::string> & cmd)
{
	Message reply;

	if (cmd.size() <= 1)
	{
		reply.add_arg(cmd[0]);
		std::string final_msg = reply.forge("127.0.0.1", ERR_NONICKNAMEGIVEN);
		sender.add_to_queue(final_msg);
		return (-1);
	}
	else
	{
		reply.add_arg(cmd[1]);
		std::cout << "nickname: " << cmd[1] << std::endl;
		if (cmd.size() > 1)
		{
			if (sender.set_nickname(cmd[1]) == false)
			{
				std::string final_msg = reply.forge("127.0.0.1", ERR_ERRONEUSNICKNAME);
				sender.add_to_queue(final_msg);
				return (-1);
			}
//		if (sender.get_user().is_nick_valid(cmd[1]) == false)
//		{
//			std::string final_msg = reply.forge("127.0.0.1", ERR_ERRONEUSNICKNAME, _msg_list);
//			sender.add_to_queue(final_msg);
//			return (-1);
//		}
//		if (sender.get_nickname() != "anonymous")
//		{
//			std::cout << "CHANGE OF NICK!!" << std::endl;
//		}
//		else if (cmd.size() > 1)
//		{
//			if (_user_list.find(cmd[1]) == _user_list.end())
//			{
//				std::cout << "I am in\n";
//				sender.get_user().nickname.set(cmd[1]);
//				_user_list[cmd[1]] = &sender.get_user(); // we update the user_list with the new nickname / user
//			}

			std::cout << "NICKNAME SET: " << sender.get_nickname() << std::endl;

		}
		return (0);
	}
	return (-1);
}

int		Command::user	(Client & sender
						,std::vector<std::string> & cmd)
{
	Message reply;

	if (sender.get_nickname() != "anonymous")
	{
		if (cmd.size() > 4)
		{
			std::string u(cmd[1]);
			std::string tmp = "";
			User & cur_user = static_cast<User &>(sender);
			cur_user.set_username(u);
			for (size_t i = 5; i < cmd.size(); i++)
				tmp += cmd[i];
			cur_user.set_realname(tmp);
//			if (_user_list.find(cmd[1]) == _user_list.end())
//				_user_list[cmd[1]] = &sender.get_user();
//			reply.add_arg(sender.get_user().fci());
			reply.add_arg(cur_user.get_nickname() + "!" + cur_user.get_username() + "@127.0.0.1");
			std::string final_msg = reply.forge("127.0.0.1", RPL_WELCOME);
			sender.add_to_queue(final_msg);
		}
		return 0;
	}
	return (-1);
}
