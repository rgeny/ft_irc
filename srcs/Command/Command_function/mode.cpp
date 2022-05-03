/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/04 01:06:43 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

int Command::mode_type(char mode)
{
	String modes_list = "OovaimnqpsrtklbeI"; // => 0 if unknown mode
	String usermodes_list = "iswo"; // 1
	String channelmodes_list = "opsitnmlbvk"; // 2
	if (modes_list.find(mode) == String::npos)
		return (0);
	if (usermodes_list.find(mode) == String::npos)
		return (2);
	return (1);
}

void Command::apply_mode(String target)
{
	size_t 	size_modestr = _cmd[2].length();
	size_t 	i = 1;
	bool	add = false;
	if (_cmd[2][0] == '+')
		add = true;
	else if (_cmd[2][0] == '-')
		add = false;
	
	while (i < size_modestr)
	{
		if (mode_type(_cmd[2][i]))
		{
			bool previous_state;
			if (mode_type(_cmd[2][i]) == 1)
			{
				previous_state = (*this->_users_it)->get_specific_mode(_cmd[2][i]);
				get_user(target)->set_specific_mode(_cmd[2][i], add);
			}
			std::cout << "USER MODES [i-s-w-o]: ["
			<< (*this->_users_it)->get_specific_mode(USERMODE_i) 
			<< "-" 
			<< (*this->_users_it)->get_specific_mode(CHANMODE_s) 
			<< "-" 
			<< (*this->_users_it)->get_specific_mode(USERMODE_w) 
			<< "-" 
			<< (*this->_users_it)->get_specific_mode(USERMODE_o) 
			<< "]\n";
		}
	}
	
	
}

e_error	Command::_mode	(void)
{
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else
	{
        std::cout << "I am in MODE\n";
        if (!has_begin_hashtag(this->_cmd[1]))
        {
            if (_cmd[1] != (*_users_it)->get_nickname())
                return (this->_err_usersdontmatch());
			else
				apply_mode(_cmd[1]);
        }
        else 
        {
            if (chan_exist(_cmd[1]) == false)
            // if ((*_chans_it).second->chan_exist(_cmd[1]) == false)
                return (this->_err_nosuchchannel());
        }

		// if (check_chan_name(this->_cmd[1]) == false || check_chan_name(this->_cmd[1]) == false)
		// 	return (ERROR_CONTINUE);
		// Channel::CHAN_USER_LIST *tmp = NULL;
		// this->_chans_it = this->_chans.find(this->_cmd[1]);
		// if (this->_chans_it == _chans.end())
		// {
		// 	this->_chans[this->_cmd[1]] = new Channel(this->_cmd[1], "");
		// 	_chans_it = this->_chans.find(this->_cmd[1]);
		// 	(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), 2);
		// }
		// else
		// 	(*_users_it)->set_chan_usermode((*_chans_it).second->get_chan_name(), 0);
		// tmp = &(*_chans_it).second->get_chan_user_list();
		// (*tmp)[(*_users_it)->get_nickname()] = *_users_it;
		// // for (Channel::CHAN_USER_LIST::iterator it = tmp->begin(); it != tmp->end(); it++)
		// // 	std::cout << (*it).second->get_nickname() << std::endl;
		return (this->_cmd_mode());
	}
	return (SUCCESS);
}