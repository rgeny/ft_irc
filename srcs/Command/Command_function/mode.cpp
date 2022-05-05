/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/05 21:07:35 by abesombe         ###   ########.fr       */
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
	if (_cmd[2][0] == '+')
		add = true;
	else if (_cmd[2][0] == '-')
		add = false;

	while (i < size_modestr)
	{
		String usermodes = "aiwroOsv";
		String chanmodes = "aimnqpsrtklbeIov";
		User *target_user = NULL;
		std::cout << "char[" << i << "] is being analyzed for mode changes\n";
		if (mode_type(_cmd[2][i])) // MODE EXISTS
		{
			std::cout << "char is a " << _cmd[2][i] << "\n";
			if (_cmd[2][i] == 'o' && _cmd.size() == 3)
				return (_err_noprivileges("Permission Denied - Only operators may set user mode o"));
			else if (!has_begin_hashtag(this->_cmd[1]) && String("asOv").find(_cmd[2][i]) != String::npos && _cmd.size() == 3)
				return (_err_umodeunknownflag(String(1, _cmd[2][i]), "is not a recognised user mode"));
			bool previous_state = false;
			if (mode_type(_cmd[2][i]) == 1 && !has_begin_hashtag(this->_cmd[1])) // USER MODE
			{
				previous_state = (*this->_users_it)->get_specific_mode(usermodes.find(_cmd[2][i]));
				this->_get_user(target)->set_specific_mode(usermodes.find(_cmd[2][i]), add);
				if (previous_state != (*this->_users_it)->get_specific_mode(usermodes.find(_cmd[2][i])))
				{
					modified = USER_MODE_MODIFIED;
					std::cout << "USER MODE UPDATED\n";
				}
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
						{
							modified = CHAN_MODE_MODIFIED;
							std::cout << "CHAN MODE UPDATED\n";
						}
					}
					else
					{
						bool is_key_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_k);
						bool is_limit_set = (*this->_chans_it).second->get_specific_mode(CHANMODE_l);

						// MODE "k"
						if (_cmd[2][i] == 'k' && add == true && is_key_set == false)
						{ 
							// std::cout << "I am in +k mode request\n";
							if (_cmd.size() < 4)
								return (this->_err_needmoreparams("k * You must specify a parameter for the key mode. Syntax: <key>."));
							(*_chans_it).second->set_key(_cmd[3]);
						}
						else if (_cmd[2][i] == 'k' && add == true && is_key_set == true)
						{
							i++;
							continue;	
						}
						else if (_cmd[2][i] == 'k' && add == false && is_key_set == true)
						{
							(*_chans_it).second->set_key("");
						}
						else if (_cmd[2][i] == 'k' && add == false && is_key_set == false)
						{
							i++;
							continue;
						}

						// MODE "l"
						
						if (_cmd[2][i] == 'l' && add == true && is_limit_set == false)
						{
							if (_cmd.size() < 4)
								return (this->_err_needmoreparams("l * You must specify a parameter for the limit mode. Syntax: <limit>."));
							(*_chans_it).second->set_limit(_cmd[3]);
						}
						else if (_cmd[2][i] == 'l' && add == true && is_limit_set == true)
						{
							i++;
							continue;	
						}
						else if (_cmd[2][i] == 'l' && add == false && is_limit_set == true)
						{
							(*_chans_it).second->set_limit(0);
						}
						else if (_cmd[2][i] == 'l' && add == false && is_limit_set == false)
						{
							i++;
							continue;
						}
						previous_state = (*this->_chans_it).second->get_specific_mode(chanmodes.find(_cmd[2][i]));
						std::cout << "previous_state: " << previous_state << std::endl;
						_chans[target]->set_specific_mode(chanmodes.find(_cmd[2][i]), add);
						if (previous_state != (*this->_chans_it).second->get_specific_mode(chanmodes.find(_cmd[2][i])))
						{
							modified = CHAN_MODE_MODIFIED;
							std::cout << "CHAN MODE UPDATED\n";
						}
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

			if (_chans_it != _chans.end() && (*_chans_it).second)
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
		else if (_cmd[2][i] == '+')
		{
			std::cout << "char is a +\n";
			add = true;
		}
		else if (_cmd[2][i] == '-')
		{
			std::cout << "char is a -\n";
			add = false;
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
	else if (this->_cmd.size() >= 3)
	{
        std::cout << "I am in MODE\n";
		if ((!has_begin_hashtag(this->_cmd[1])) && (_cmd[1] != (*_users_it)->get_nickname()))
			return (this->_err_usersdontmatch());
		if ((has_begin_hashtag(this->_cmd[1])) && this->_chan_exist(_cmd[1]) == false)
			return (this->_err_nosuchchannel());
		else
			_chans_it = _chans.find(_cmd[1]);
		ret = apply_mode(_cmd[1]);
		if (ret == CHAN_MODE_MODIFIED)
			return (this->_cmd_mode(1));
		else if (ret == USER_MODE_MODIFIED)
			return (this->_cmd_mode(0));
	}
	return (SUCCESS);
}
