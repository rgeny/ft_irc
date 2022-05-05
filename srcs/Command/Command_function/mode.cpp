/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/05 16:08:05 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

int Command::mode_type(char mode)
{
	String modes_list = "aiswoOpstnmlbvk"; // => 0 if unknown mode OovaimnqpsrtklbeI
	String usermodes_list = "aiwroOsv"; // 1
	String channelmodes_list = "aimnqpsrtklbeIov"; // 2
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
	// if (_cmd[2][0] == '+')
	// 	add = true;
	// else if (_cmd[2][0] == '-')
	// 	add = false;

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
		String usermodes = "aiwroOsv";
		String chanmodes = "aimnqpsrtklbeIov";
		User *target_user = NULL;
		if (mode_type(_cmd[2][i])) // MODE EXISTS
		{
			if (_cmd[2][i] == '+')
			{
				add = true;
				i++;
				continue;
			}
			else if (_cmd[2][i] == '-')
			{
				add = false;
				i++;
				continue;
			}
			if (_cmd[2][i] == 'o' && _cmd.size() == 3)
				return (_err_noprivileges("Permission Denied - Only operators may set user mode o"));
			else if (String("asOv").find(_cmd[2][i]) != String::npos && _cmd.size() == 3)
				return (_err_umodeunknownflag(String(1, _cmd[2][i]), "is not a recognised user mode"));
			bool previous_state = false;
			if (mode_type(_cmd[2][i]) == 1 && !has_begin_hashtag(this->_cmd[1])) // USER MODE
			{

				previous_state = (*this->_users_it)->get_specific_mode(usermodes.find(_cmd[2][i]));
				this->_get_user(target)->set_specific_mode(usermodes.find(_cmd[2][i]), add);
				if (previous_state != (*this->_users_it)->get_specific_mode(usermodes.find(_cmd[2][i])))
					modified = 99;
			}
			else if (mode_type(_cmd[2][i])) // CHANNEL MODE
			{

				std::cout << "Nb of channels: " << _chans.size() << std::endl;
				bool chan_operator = is_operator((*_users_it)->get_nickname(), *_chans_it->second);
				if (_chans.size() > 0 && chan_operator == true)
				{
					if ((_cmd[2][i] == 'o' || _cmd[2][i] == 'v') &&_cmd.size() > 3)
					{
						std::cout << "Update modes 'o' ou 'v' sur une target" << std::endl;
						if (this->_user_exist(_cmd[3]) == false)
							return (_err_nosuchnick());
						if (user_exist_in_chan(*_chans_it->second, _cmd[3]) == false)
							return (_err_usernotinchannel());
						target_user = _get_user(_cmd[3]);
						// std::cout << "Target_user: " << target_user->get_nickname() << std::endl;
						// std::cout << "index in MODE_VEC: " << usermodes.find(_cmd[2][i]) << " - add = " << add << std::endl;
						previous_state = target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(_cmd[2][i])];
						// std::cout << "previous_state: " << previous_state << std::endl;
						target_user->set_chan_usermode(_cmd[1], usermodes.find(_cmd[2][i]), add);
						// std::cout << "state_afterwards: " << previous_state << std::endl;
						if (previous_state != target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(_cmd[2][i])])
							modified = 99;
					}
					else
					{
						previous_state = (*this->_chans_it).second->get_specific_mode(chanmodes.find(_cmd[2][i]));
						_chans[target]->set_specific_mode(chanmodes.find(_cmd[2][i]), add);
						if (previous_state != (*this->_chans_it).second->get_specific_mode(chanmodes.find(_cmd[2][i])))
							modified = 99;
					}
					// o et v sont dans chan_usermode
					// w, O et i sont dans user_mode
					std::cout << "USER MODES current_user [o|w|O|i|v]: ["					
					<< (*_users_it)->get_chan_usermode_vec(this->_cmd[1])[USERMODE_o]
					<< "|" 
					<< (*_users_it)->get_specific_mode(USERMODE_w) 
					<< "|" 
					<< (*_users_it)->get_chan_usermode_vec(this->_cmd[1])[USERMODE_O]
					<< "|" 
					<< (*_users_it)->get_specific_mode(USERMODE_i) 
					<< "|" 
					<< (*_users_it)->get_chan_usermode_vec(this->_cmd[1])[USERMODE_v]
					<< "]\n";
					if (target_user)
					{
						std::cout << "USER MODES target_user [o|w|O|i|v]: ["
						<< target_user->get_chan_usermode_vec(this->_cmd[1])[USERMODE_o]
						<< "|" 
						<< target_user->get_specific_mode(USERMODE_w) 
						<< "|" 
						<< target_user->get_chan_usermode_vec(this->_cmd[1])[USERMODE_O]
						<< "|" 
						<< target_user->get_specific_mode(USERMODE_i) 
						<< "|" 
						<< target_user->get_chan_usermode_vec(this->_cmd[1])[USERMODE_v]
						<< "]\n";
					}
				}
				else if (_chans.size() > 0 && chan_operator == false)
					return (_err_chanoprivsneeded("You must have channel halfop access or above to set channel mode m"));
			}

			if (_chans.size() > 0)
			{
			// std::cout << "cur_chan: " << (*this->_chans_it).second->get_chan_name() << std::endl;				
			std::cout << "CHAN MODES [p|s|i|t|n|m|l|b|k]: ["
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
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_m) 
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_l) 
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_b)
			<< "|" 
			<< (*this->_chans_it).second->get_specific_mode(CHANMODE_k) 
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
				return (this->_cmd_mode(0));
			return (SUCCESS);
        }
        else 
        {
            if (this->_chan_exist(_cmd[1]) == false)
                return (this->_err_nosuchchannel());
			if (_cmd.size() >= 3)
			{
				ret = apply_mode(_cmd[1]);
				if (ret == MODE_MODIFIED)
					return (this->_cmd_mode(1));
				return (SUCCESS);
			}
        }

	}
	return (SUCCESS);
}
