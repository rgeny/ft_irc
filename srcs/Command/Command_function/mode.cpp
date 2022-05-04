/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/04 21:52:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

int Command::mode_type(char mode)
{
	String modes_list = "aiswoOpstnmlbvk"; // => 0 if unknown mode OovaimnqpsrtklbeI
	String usermodes_list = "aiwroOsv"; // 1
	String channelmodes_list = "psitnmlbvk"; // 2
	if (modes_list.find(mode) == String::npos)
		return (0);
	if (usermodes_list.find(mode) == String::npos)
		return (2);
	return (1);
}

int Command::apply_mode(String target)
{
	size_t 	size_modestr = _cmd[2].length();
	size_t 	i = 0;
	bool	add = true;
	int		modified = 0;
	std::cout << "I am in APPLY_MODE\n";
	if (_cmd[2][0] == '+')
		add = true;
	else if (_cmd[2][0] == '-')
		add = false;

	if (has_begin_hashtag(this->_cmd[1]))
	{
		if (!this->_chan_exist(_cmd[1]))
			return(_err_nosuchchannel());
		// if (_cmd[2][0] != '-' && _cmd[2][0] != '+')
		// {
		// 	if (_cmd.size() < 4)
		// 	{
				
		// 	}
		// 	// if (!user_exist(_cmd[2]))
		// 	// 	return(_err_nosuchnick());
		// }
			
		// if (!user_exist(_cmd[1]))
		// 	return(_err_nosuchnick());
		
	}

	while (i < size_modestr)
	{
		if (mode_type(_cmd[2][i]))
		{
			if (_cmd[2][i] == 'o')
				return (_err_noprivileges("Permission Denied - Only operators may set user mode o"));
			else if (String("asOv").find(_cmd[2][i]) != String::npos)
				return (_err_umodeunknownflag(String(1, _cmd[2][i]), "is not a recognised user mode"));
			bool previous_state = false;
			if (mode_type(_cmd[2][i]) == 1 && !has_begin_hashtag(this->_cmd[1])) // USER
			{
				String usermodes = "aiwroOsv";
				previous_state = (*this->_users_it)->get_specific_mode(usermodes.find(_cmd[2][i]));
				this->_get_user(target)->set_specific_mode(usermodes.find(_cmd[2][i]), add);
				if (previous_state != (*this->_users_it)->get_specific_mode(usermodes.find(_cmd[2][i])))
					modified = 99;
			}
			else if (mode_type(_cmd[2][i]) == 2) // CHANNEL
			{
				String chanmodes = "aimnqpsrtklbeI";
				std::cout << "Nb of channels: " << _chans.size() << std::endl;
				if (_chans.size() > 0)
				{
					previous_state = (*this->_chans_it).second->get_specific_mode(chanmodes.find(_cmd[2][i]));
					_chans[target]->set_specific_mode(chanmodes.find(_cmd[2][i]), add);
					if (previous_state != (*this->_chans_it).second->get_specific_mode(chanmodes.find(_cmd[2][i])))
						modified = 99;
				}
			}

			if (_chans.size() > 0)
			{
			// std::cout << "cur_chan: " << (*this->_chans_it).second->get_chan_name() << std::endl;				
			std::cout << "CHAN MODES [p|s|i|t|n|b]: ["
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_p) 
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_s) 
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_i) 
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_t) 
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_n) 
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_b) 
			<< "]\n";
			}
		}
		i++;
	}
	return (modified);
}

e_error	Command::_mode	(void)
{
	int ret;
	
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else if (this->_cmd.size() == 2)
	{
		_rpl_channelmodeis();
		return (_rpl_creationtime());
	}
	else
	{
        std::cout << "I am in MODE\n";
        if (!has_begin_hashtag(this->_cmd[1]))
        {
            if (_cmd[1] != (*_users_it)->get_nickname())
                return (this->_err_usersdontmatch());
			ret = apply_mode(_cmd[1]);
			if (ret == MODE_MODIFIED)
				return (this->_cmd_mode());
			return (SUCCESS);
        }
        else 
        {
            if (this->_chan_exist(_cmd[1]) == false)
                return (this->_err_nosuchchannel());
			if (_cmd.size() == 3)
			{
				ret = apply_mode(_cmd[1]);
				if (ret == MODE_MODIFIED)
					return (this->_cmd_mode());
				return (SUCCESS);
			}
        }


		// MODE Chichi +i
		// MODE #aaa +b 62.234.20.10
		// MODE #aaa +v Chichi
		// MODE #aaa +im
		
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
