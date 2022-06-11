/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/11 18:29:28 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void Command::update_user_mode(bool &previous_state, int &modified, int i, bool &add, String target)		
{
	String usermodes = USERMODES_LIST;
	size_t cur_mode = usermodes.find(_cmd[2][i]);
	previous_state = (*this->_users_it)->get_specific_mode(cur_mode);
	this->_get_user(target)->set_specific_mode(cur_mode, add);
	if (previous_state != (*this->_users_it)->get_specific_mode(cur_mode))
	{
		modified = USER_MODE_MODIFIED;
		std::cout << "USER MODE UPDATED\n";
	}
}

void Command::display_chan_mode(Channel *cur_chan)
{
	std::cout << "CHAN MODES [p|s|i|t|n|m|l|b|k]: ["
	<< cur_chan->get_specific_mode(CHANMODE_p)
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_s) 
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_i) 
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_t) 
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_n)
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_m) 
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_l) 
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_b)
	<< "|" 
	<< cur_chan->get_specific_mode(CHANMODE_k) 
	<< "]\n";
}

void Command::display_user_mode(User* target_user, String user_type)
{
	std::cout << "USER MODES " << user_type << " [o|w|O|i|v]: ["
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

int Command::mode_type(char mode)
{
	String modes_list = MODES_LIST; // => 0 if unknown mode OovaimnqpsrtklbeI
	String usermodes_list = USERMODES_LIST; // 1
	String channelmodes_list = CHANMODES_LIST; // "aimnqpsrtklbeIov" // 2
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
	Channel* cur_chan = (*this->_chans_it).second;
	User* cur_user = (*_users_it);
	bool	add = true;
	int		modified = 0;
	
	if (_cmd[2][0] == '+')
		add = true;
	else if (_cmd[2][0] == '-')
		add = false;

	while (i < size_modestr)
	{
		String usermodes = USERMODES_LIST;
		String chanmodes = CHANMODES_LIST;
		User *target_user = NULL;
		bool is_channel = has_begin_hashtag(this->_cmd[1]);
		std::cout << "char[" << i << "] is being analyzed for mode changes\n";
		char mode_char = _cmd[2][i];
		if (mode_type(mode_char)) // MODE EXISTS
		{
			std::cout << "char is a " << mode_char << "\n";
			
			if (mode_char == 'o' && _cmd.size() == 3)
				return (_err_noprivileges("Permission Denied - Only operators may set user mode o"));
			else if (!has_begin_hashtag(this->_cmd[1]) && String("asOv").find(mode_char) != String::npos && _cmd.size() == 3)
				return (_err_umodeunknownflag(String(1, mode_char), "is not a recognised user mode"));

			bool previous_state = false;
			if (mode_type(mode_char) == 1 && !is_channel) // USER MODE
				update_user_mode(previous_state, modified, i, add, target);
			else if (mode_type(mode_char) && is_channel) // CHANNEL MODE
			{
				Channel::CHAN_BAN_LIST *chan_ban_list = NULL;
				std::cout << "Nb of channels: " << _chans.size() << std::endl;
				bool chan_operator = is_operator((*_users_it)->get_nickname(), *cur_chan);
				if ((_chans.size() > 0 && chan_operator == true) || (mode_char == 'b'))
				{
					if ((mode_char == 'o' || mode_char == 'v') && _cmd.size() > 3)
					{
						std::cout << "Update modes 'o' ou 'v' sur une target" << std::endl;
						if (this->_user_exist(_cmd[3]) == false)
							return (_err_nosuchnick(_cmd[3]));
						if (user_exist_in_chan(*cur_chan, _cmd[3]) == false)
							return (_err_usernotinchannel());
						target_user = _get_user(_cmd[3]);
						previous_state = target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(mode_char)];
						target_user->set_chan_usermode(_cmd[1], usermodes.find(mode_char), add);
						if (previous_state != target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(mode_char)])
						{
							modified = CHAN_MODE_MODIFIED;
							std::cout << "CHAN MODE UPDATED\n";
						}
					}
					else
					{
						bool is_key_set = cur_chan->get_specific_mode(CHANMODE_k);
						bool is_limit_set = cur_chan->get_specific_mode(CHANMODE_l);
						chan_ban_list = &(*_chans_it).second->get_chan_ban_list();

						// MODE "k"
						if (mode_char == 'k' && add == true && is_key_set == false)
						{ 
							// std::cout << "I am in +k mode request\n";
							if (_cmd.size() < 4)
								return (this->_err_needmoreparams("k * You must specify a parameter for the key mode. Syntax: <key>."));
							cur_chan->set_key(_cmd[3]);
						}
						else if (mode_char == 'k' && add == true && is_key_set == true)
						{
							i++;
							continue;	
						}
						else if (mode_char == 'k' && add == false && is_key_set == true)
						{
							cur_chan->set_key("");
						}
						else if (mode_char == 'k' && add == false && is_key_set == false)
						{
							i++;
							continue;
						}

						// MODE "l"
						
						if (mode_char == 'l' && add == true && is_limit_set == false)
						{
							if (_cmd.size() < 4)
								return (this->_err_needmoreparams("l * You must specify a parameter for the limit mode. Syntax: <limit>."));
							cur_chan->set_limit(_cmd[3]);
						}
						else if (mode_char == 'l' && add == true && is_limit_set == true)
						{
							i++;
							continue;	
						}
						else if (mode_char == 'l' && add == false && is_limit_set == true)
						{
							cur_chan->set_limit(0);
						}
						else if (mode_char == 'l' && add == false && is_limit_set == false)
						{
							i++;
							continue;
						}

						// MODE "b"
						std::cout << "b: _cmd.size(): " << _cmd.size() << std::endl;
						size_t count_mode_letters = 0;
						for (size_t i = 0 ; i < _cmd[2].size(); i++)
						{
							if (mode_char != '+' && mode_char != '-')
								count_mode_letters++;
						}
							
						if (mode_char == 'b' && add == true && _cmd.size() < 4)
						{
							if (chan_ban_list->size() > 0)
								_rpl_banlist();
							if (count_mode_letters > 1)
								_rpl_endofbanlist();
							else
								return (_rpl_endofbanlist());
						}
						else if (mode_char == 'b' && add == true && _cmd.size() > 3)
						{
							if (!chan_operator)
							    return (_err_chanoprivsneeded());
							if (chan_ban_list->size() >= CHAN_BAN_LIST_MAX_SIZE)
								return (_err_banlistfull());
							if (chan_ban_list->find(_cmd[3]) == chan_ban_list->end())
							{
								Channel::PAIR_BAN_CREATORNAME_TIME bpair = std::make_pair(*_users_it, time(0));
								chan_ban_list->insert(std::make_pair(_cmd[3], bpair));
								_cmd[3] = _cmd[3] + "!*@*";
							}
						}
						else if (mode_char == 'b' && add == false && _cmd.size() > 3)
						{
							String needle_nick;
							if (_cmd[3].substr(_cmd[3].length() - 4) == "!*@*")
							{
								needle_nick = _cmd[3].substr(0, _cmd[3].length() - 4);
								std::cout << "needle_nick: " << needle_nick << std::endl;
								if (!chan_operator)
									return (_err_chanoprivsneeded());
								chan_ban_list->erase(needle_nick);
								modified = CHAN_MODE_MODIFIED;
							}
						}


						previous_state = cur_chan->get_specific_mode(chanmodes.find(mode_char));
						std::cout << "previous_state: " << previous_state << std::endl;
						_chans[target]->set_specific_mode(chanmodes.find(mode_char), add);
						if (previous_state != cur_chan->get_specific_mode(chanmodes.find(mode_char)))
						{
							modified = CHAN_MODE_MODIFIED;
							std::cout << "CHAN MODE UPDATED\n";
						}
						if (mode_char == 'b')
							_chans[target]->set_specific_mode(chanmodes.find(mode_char), false);
					}
					display_user_mode(cur_user, "current_user");
					if (target_user != NULL)
						display_user_mode(target_user, "target_user");
				}
				else if (_chans.size() > 0 && chan_operator == false && mode_char == 'm')
					return (_err_chanoprivsneeded("You must have channel halfop access or above to set channel mode m"));
			}
			else
			{
				return (_err_umodeunknownflag("m:", "is not a recognised user mode."));
			}

			if (_chans_it != _chans.end() && cur_chan != NULL)
				display_chan_mode(cur_chan);
		}
		else if (mode_char == '+')
			add = true;
		else if (mode_char == '-')
			add = false;
		i++;
	}
	return (modified);
}

e_error	Command::_mode	(void)
{
	int ret;
	bool is_channel = has_begin_hashtag(this->_cmd[1]);
	Channel *cur_chan = NULL;
	
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams());
	else 
	{
		if (is_channel == false && (_cmd[1] != (*_users_it)->get_nickname()))
			return (this->_err_usersdontmatch());

		if (is_channel == true && this->_chan_exist(_cmd[1]) == false)
			return (this->_err_nosuchchannel());
		else
		{
			_chans_it = _chans.find(_cmd[1]);
			if (_chans_it != _chans.end())
			{
				cur_chan = (*this->_chans_it).second;
				bool chan_operator = is_operator((*_users_it)->get_nickname(), *cur_chan);
				if ((cur_chan->get_specific_mode(CHANMODE_p) == true
				|| cur_chan->get_specific_mode(CHANMODE_s) == true) && !chan_operator)
					return (this->_err_nosuchchannel());
			}
		}
		if (this->_cmd.size() == 2)
		{
			_rpl_channelmodeis();
			return (_rpl_creationtime());
		}
		else if (this->_cmd.size() >= 3)
		{
			ret = apply_mode(_cmd[1]);
			if (ret == CHAN_MODE_MODIFIED)
				return (this->_cmd_mode(1));
			else if (ret == USER_MODE_MODIFIED)
				return (this->_cmd_mode(0));
		}
	}
	return (SUCCESS);
}
