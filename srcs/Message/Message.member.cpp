/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:53:45 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/20 16:47:37 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

std::string const & Message::aggreg(void)
{
	std::string *tmp = new std::string(_sender + " " + msg_code.get() + " " + _receiver + " " + msg_content.get() + "\r\n");
	return (*tmp);
}

void Message::add_arg(std::string &arg)
{
	this->msg_args.push_back(arg);
}

size_t Message::size_arg(void)
{
	return(this->msg_args.size());
}

std::string const & Message::forge(std::string & sender, std::string & msg_code, std::map<std::string, std::string> & msg_list)
{
	std::string content = get_msg(msg_code, msg_args, msg_list);
	std::string *tmp = new std::string(sender + " " + msg_code + " " + _receiver + " " + content + "\r\n");
	return (*tmp);
}

std::string Message::get_msg(std::string & msg_code, std::vector<std::string> & args, std::map<std::string, std::string> & msg_list)
{
	std::string msg_template;
	msg_template = msg_list[msg_code];
	return(replace_tags(msg_template, args));
}

std::string Message::replace_tags(std::string msg_template, std::vector<std::string> &args)
{
	int position_tag = 0;
	size_t pos_opentag;
	size_t pos_closetag;
	size_t tag_len;
	for (std::vector<std::string>::iterator it = args.begin(); it < args.end(); it++)
	{
		pos_opentag = msg_template.find("<", position_tag);
		if (pos_opentag != std::string::npos)
		{
			pos_closetag = msg_template.find(">", pos_opentag + 1);
			if (pos_closetag != std::string::npos)
			{
				tag_len = pos_closetag - pos_opentag + 1;
				msg_template = msg_template.replace(pos_opentag, tag_len, *it);
				position_tag = pos_opentag + (*it).length();
			}
		}
	}
	return (msg_template);
}
