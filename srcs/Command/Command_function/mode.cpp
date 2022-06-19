/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/19 15:23:13 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

String Command::char_to_String(char c)
{
	std::stringstream ss;
	ss << c;
	std::string s = ss.str();
	String mode_string = String(s);
	return (mode_string);
}

String Command::strip_orphan_sign(String mode_change)
{
	String short_mode;
	size_t str_size = mode_change.size();

	for (size_t i = 0; i < str_size; i++)
	{
		if (!((mode_change[i] == '+' || mode_change[i] == '-') && (mode_change[i + 1] == '+' || mode_change[i + 1] == '-' || i + 1 >= str_size)))
			short_mode = short_mode + mode_change[i];
	}
	return (short_mode);
}

void Command::update_user_mode(bool &previous_state, int &modified, int i, bool &add, String target, String *mode_change)		
{

	std::string usermodes = USERMODES_LIST;
	size_t cur_mode = usermodes.find(_cmd[2][i]);
	previous_state = (*this->_users_it)->get_specific_mode(cur_mode);

	this->_get_user(target)->set_specific_mode(cur_mode, add);
	if (previous_state != (*this->_users_it)->get_specific_mode(cur_mode))
	{
		modified = USER_MODE_MODIFIED;
		*mode_change = *mode_change + char_to_String(_cmd[2][i]);
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

void Command::display_user_mode(User* target_user, String user_type, String chan_name)
{
	std::cout << "current_user = " << target_user->get_nickname() << std::endl;
	std::cout << "USER MODES " << user_type << " [o|w|O|i|v]: ["
	<< target_user->get_chan_usermode_vec(chan_name)[USERMODE_o]
	<< "|" 
	<< target_user->get_specific_mode(USERMODE_w) 
	<< "|" 
	<< target_user->get_chan_usermode_vec(chan_name)[USERMODE_O]
	<< "|" 
	<< target_user->get_specific_mode(USERMODE_i) 
	<< "|" 
	<< target_user->get_chan_usermode_vec(chan_name)[USERMODE_v]
	<< "]\n";
}

String Command::get_user_mode(User* target_user)
{
	String user_mode;
	user_mode = user_mode 
				+ (target_user->get_specific_mode(USERMODE_i) ? "i" : "")
				+ (target_user->get_specific_mode(USERMODE_o) ? "o" : "")
				+ (target_user->get_specific_mode(USERMODE_w) ? "w" : "");

	return (user_mode);
}

int Command::mode_type(char mode)
{
	std::string modes_list = MODES_LIST; // => 0 if unknown mode OovaimnqpsrtklbeI
	std::string usermodes_list = USERMODES_LIST; // 1
	std::string channelmodes_list = CHANMODES_LIST; // "aimnqpsrtklbeIov" // 2
	if (modes_list.find(mode) == std::string::npos)
		return (0);
	if (usermodes_list.find(mode) == std::string::npos)
		return (2);
	return (1);
}

bool Command::invalid_mode_input(String input)
{
	
	for (size_t i = 0; i < input.size() ; i++)
	{
		if (i == 0 && input[i] == '+')
			continue;
		if (!isdigit(input[i]))
			return(true);
	}
	return (false);
}

int Command::apply_mode(String target, String *mode_change)
{
	size_t 	size_modestr = _cmd[2].length();
	size_t 	i = 0;
	size_t	count_b = 0;
	Channel* cur_chan = (*this->_chans_it).second;
	User* 	cur_user = (*_users_it);
	String 	err_msg;
	bool	add = true;
	int		modified = 0;
	size_t	arg_num = 3;
	
	if (_cmd[2][0] == '+')
	{
		*mode_change = *mode_change + String("+");
		add = true;
	}
	else if (_cmd[2][0] == '-')
	{
		*mode_change = *mode_change + String("-");
		add = false;
	}

	while (i < size_modestr)
	{
		std::string usermodes = USERMODES_LIST;
		std::string chanmodes = CHANMODES_LIST;
		String erroneous_elem;
		bool arg_valid = false;
		bool l_change = false;
		User *target_user = NULL;
		bool is_channel = has_begin_hashtag(this->_cmd[1]);
		char mode_char = _cmd[2][i];
		std::cout << "char[" << i << "] = " << mode_char << " is being analyzed for mode changes\n";
		std::cout << "arg_num: " << arg_num << std::endl;
		erroneous_elem = String(_cmd[1] + " +" + mode_char);

		if (mode_type(mode_char) && chanmodes.find(mode_char) != std::string::npos) // MODE EXISTS
		{
			/* Check if mode is either 'olvk' which requires argument */

			if (has_begin_hashtag(this->_cmd[1]) 
				&& (((mode_char == 'o' || mode_char == 'l' || mode_char == 'v') && add == true) || mode_char == 'k')
				&& arg_num > _cmd.size() - 1)
			{
				String param_name = (mode_char == 'o' ? "op" : mode_char == 'v' ? "voice" : mode_char == 'k' ? "key": "limit");
				String syntax = (mode_char == 'o' || mode_char == 'v' ? "nick" : param_name);
				err_msg = String(":You must specify a parameter for the ") + param_name + String(" mode. Syntax: <") + syntax + String(">.");
				this->_err_needmoreparams(erroneous_elem + " * ", err_msg);
				arg_num++;
				i++;
				continue;
			}
			/* Check if _cmd[1] is a user and if the mode_char is a usermode or not */
			else if (!has_begin_hashtag(this->_cmd[1]) 
					&& std::string("awrOosv").find(mode_char) != std::string::npos
					&& _cmd.size() == 3)
			{
				_err_umodeunknownflag(String(1, mode_char), "is not a recognised user mode");
				i++;
				continue;
			}

			/* Check if limit argument can be recognized as a strictly positive integer or not */
			if (mode_char == 'l' && is_channel && add == true && (invalid_mode_input(_cmd[arg_num]) || strtol(_cmd[arg_num].c_str(), NULL, 10) == 0))
			{
				err_msg = String(":Invalid limit mode parameter. Syntax: <limit>.");
				this->_err_needmoreparams(erroneous_elem + " " + _cmd[arg_num] + " ", err_msg);
				i++;
				continue;
			}
			bool previous_state = false;
			if (mode_type(mode_char) == 1 && !is_channel) // USER MODE
				update_user_mode(previous_state, modified, i, add, target, mode_change);
			else if (mode_type(mode_char) == 1 && is_channel && mode_char != 'o' && mode_char != 'v' && mode_char != 's' && mode_char != 'i') // WRONG MODES FOR CHANNELS => THESE ARE USER MODES, NOT CHAN MODES
			{
				_err_umodeunknownflag(String(1, mode_char), "is not a recognised chan mode");
				i++;
				continue;
			}
			else if (mode_type(mode_char) && is_channel) // CHANNEL MODE
			{
				Channel::CHAN_BAN_LIST *chan_ban_list = NULL;
				String nickname = (*_users_it)->get_nickname();
				bool chan_operator = is_operator(nickname, *cur_chan);
				
				/* Check if the current user has the right priviledge level to request mode change */
				if (_chans.size() > 0 && chan_operator == false 
					&& (mode_char == 'm' || mode_char == 'p' || mode_char == 's' || mode_char == 't' || mode_char == 'l' || (mode_char == 'b' && arg_num <= _cmd.size() - 1) || mode_char == 'k'))
				{
					this->_err_chanoprivsneeded(String("You must have channel halfop access or above to set channel mode ") + mode_char);
					arg_num++;
					i++;
					continue;
				}
				else if (_chans.size() > 0 && chan_operator == false && mode_char == 'o')
				{
					this->_err_chanoprivsneeded("You must have channel op access or above to set channel mode o");
					arg_num++;
					i++;
					continue;
				}
				else if ((_chans.size() > 0 && chan_operator == true) || (mode_char == 'b'))
				{
					if ((mode_char == 'o' || mode_char == 'v') && arg_num <= _cmd.size() - 1)
					{
						/* Check if the target user of o or v mode change does exist or not */
						if (this->_user_exist(_cmd[arg_num]) == false)
						{
							this->_err_nosuchnick(_cmd[arg_num]);
							arg_num++;
							i++;
							continue;
						}
						
						/* Check if the target user of o or v mode change does exist IN THE TARGET CHANNEL or not */
						if (this->user_exist_in_chan(*cur_chan, _cmd[arg_num]) == false)
						{
							this->_err_usernotinchannel(_cmd[arg_num], cur_chan->get_chan_name());
							arg_num++;
							i++;
							continue;
						}

						target_user = _get_user(_cmd[arg_num]);
						
						if (target_user->get_chan_usermode().size() == 0)
							previous_state = false;
						else if (target_user->get_chan_usermode_vec(_cmd[1]).size() > 0)
							previous_state = target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(mode_char)];
						
						std::cout << "Previous_state = " << previous_state << " - add = " << add << std::endl; 
						
						target_user->set_chan_usermode(_cmd[1], usermodes.find(mode_char), add);

						if (previous_state != target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(mode_char)])
						{
							/* Check if the mode change did modify something or not -> if yes, add this mode char to the final reply */
							modified = CHAN_MODE_MODIFIED;
							*mode_change = *mode_change + char_to_String(mode_char);
							std::cout << "CHAN MODE UPDATED\n";
						}
						arg_num++;
					}
					else
					{
						bool is_key_set = cur_chan->get_specific_mode(CHANMODE_k);
						bool is_limit_set = cur_chan->get_specific_mode(CHANMODE_l);
						chan_ban_list = &(*_chans_it).second->get_chan_ban_list();

						// MODE "k"
						if (mode_char == 'k' && add == true && is_key_set == false) // +k with no previous key set yet
						{ 
							cur_chan->set_key(_cmd[arg_num]);
							arg_num++;
						}
						else if (mode_char == 'k' 
								&& ((add == true && is_key_set == true) || (add == false && is_key_set == false))) // +k while there is already a set key or -k with no set key => ignore both
						{
							i++;
							arg_num++;
							continue;	
						}
						else if (mode_char == 'k' && add == false && is_key_set == true && _cmd[arg_num] != cur_chan->get_key()) // -k wrong_key
						{
							arg_num++;
							_err_keyset();
							i++;
							continue;
						}
						else if (mode_char == 'k' && add == false && is_key_set == true && _cmd[arg_num] == cur_chan->get_key()) // -k right_key => reset key to ""
						{
							arg_num++;
							cur_chan->set_key("");
						}

						// MODE "l"
						size_t new_limit = 0;
						if (arg_num <= _cmd.size() - 1)
							new_limit = strtol(_cmd[arg_num].c_str(), NULL, 10);
						if (mode_char == 'l' && add == true && (is_limit_set == false || (is_limit_set == true && new_limit > 0 && cur_chan->get_limit() != new_limit))) // +l with no previously set limit
						{
							l_change = true;
							cur_chan->set_limit(_cmd[arg_num]); // set new limit
							arg_num++;
						}
						else if (mode_char == 'l' 
								&& ((add == true && is_limit_set == true && cur_chan->get_limit() == new_limit) || (add == false && is_limit_set == false))) // +l while limit is already set or -l with no set key => ignore
						{
							i++;
							arg_num++;
							continue;	
						}
						else if (mode_char == 'l' && add == false && is_limit_set == true) // -l while limit is set.
						{
							cur_chan->set_limit(0); // remove limit
							arg_num++;
						}
						
						// MODE "b"
						/* Determine if b is the first mode letter - if yes, then display the ban_list if very 1st b- otherwise no ban_list display */
						bool flag_b = true;

						size_t count_mode_letters = 0;
						for (size_t j = 0 ; j < _cmd[2].size(); j++)
						{
							if (_cmd[2][j] != '+' && _cmd[2][j] != '-')
							{
								if (count_mode_letters == 0 && _cmd[2][j] != 'b')
									flag_b = false;
								count_mode_letters++;
							}
						}
						if (mode_char == 'b')
							count_b++;
						std::cout << "count_b: " << count_b << " - flag_b = " << flag_b << std::endl;
							
						if (mode_char == 'b' && add == true && flag_b == true && count_b == 1 && (arg_num > _cmd.size() - 1))
						{
							if (chan_ban_list->size() > 0)
								_rpl_banlist();
							_rpl_endofbanlist();
						}
						else if (mode_char == 'b' && add == true && arg_num <= _cmd.size() - 1)
						{
							if (!chan_operator)
							{
							    this->_err_chanoprivsneeded();
								arg_num++;
								i++;
								continue;
							}
							if (chan_ban_list->size() >= CHAN_BAN_LIST_MAX_SIZE)
							{
								this->_err_banlistfull();
								arg_num++;
								i++;
								continue;
							}
							if (chan_ban_list->find(_cmd[arg_num]) == chan_ban_list->end())
							{
								Channel::PAIR_BAN_CREATORNAME_TIME bpair = std::make_pair(*_users_it, time(0));
								chan_ban_list->insert(std::make_pair(_cmd[arg_num], bpair));
								_cmd[arg_num] = _cmd[arg_num] + "!*@*";
								arg_valid = true;
							}
							else if (chan_ban_list->find(_cmd[arg_num]) != chan_ban_list->end())
							{
								_err_alreadyinbanlist(_cmd[1], _cmd[arg_num] + "!*@*");
								arg_num++;
								i++;
								continue;
							}
							arg_num++;
						}
						else if (mode_char == 'b' && add == false && arg_num <= _cmd.size() - 1)
						{
							String needle_nick;
							if (_cmd[arg_num].size() >= 4 && _cmd[arg_num].substr(_cmd[arg_num].length() - 4) == "!*@*")
							{
								needle_nick = _cmd[arg_num].substr(0, _cmd[arg_num].length() - 4);
								if (!chan_operator)
								{
									this->_err_chanoprivsneeded();
									arg_num++;
									i++;
									continue;
								}
								if (chan_ban_list->find(needle_nick) == chan_ban_list->end())
								{
									this->_err_notinbanlist(_cmd[1], _cmd[arg_num]);
									arg_num++;
									i++;
									continue;
								}
								else
									chan_ban_list->erase(needle_nick);
								modified = CHAN_MODE_MODIFIED;
								arg_valid = true;
								arg_num++;
							}
							else
							{
								this->_err_notinbanlist(_cmd[1], _cmd[arg_num]);
								arg_num++;
								i++;
								continue;
							}
						}

						previous_state = cur_chan->get_specific_mode(chanmodes.find(mode_char));

						_chans[target]->set_specific_mode(chanmodes.find(mode_char), add);
						if (previous_state != cur_chan->get_specific_mode(chanmodes.find(mode_char)) || (mode_char == 'b' && add == false && arg_valid) || l_change)
						{
							if (mode_char != 'b' || (mode_char == 'b' && arg_valid) || l_change)
							{
								modified = CHAN_MODE_MODIFIED;
								*mode_change = *mode_change + char_to_String(mode_char);
								std::cout << "CHAN MODE UPDATED\n";
							}
						}
						if (mode_char == 'b')
							_chans[target]->set_specific_mode(chanmodes.find(mode_char), false);
					}
					if (cur_user != NULL && !_cmd[1].empty() && _chan_exist(_cmd[1]))
						display_user_mode(cur_user, "current_user", _cmd[1]);
					if (target_user != NULL && !_cmd[1].empty() && _chan_exist(_cmd[1]))
						display_user_mode(target_user, "target_user", _cmd[1]);
				}
			}
			else
			{
				std::cout << "mode_char perdu: [" << mode_char << "]"<< std::endl;
				String mode_str = mode_char + "";
				std::cout << "mode_str perdu: [" << mode_char << "]"<< std::endl;
				this->_err_umodeunknownflag(char_to_String(mode_char), "is not a recognised user mode.");
				arg_num++;
				i++;
				continue;
			}

			if (_chans_it != _chans.end() && cur_chan != NULL)
				display_chan_mode(cur_chan);
		}
		else if (mode_char == '+')
		{
			add = true;
			*mode_change = *mode_change + String("+");
		}
		else if (mode_char == '-')
		{
			add = false;
			*mode_change = *mode_change + String("-");
		}
		else
		{	
			_err_umodeunknownflag(char_to_String(mode_char), ":is not a recognised mode flag.");
		}
		i++;
	}
	return (modified);
}

/*
If <modestring> is given, the supplied modes will be applied, and a MODE message will be sent to the user containing the changed modes
*/

e_error	Command::_mode	(void)
{
	int ret;
	bool is_channel = has_begin_hashtag(this->_cmd[1]);
	Channel *cur_chan = NULL;
	
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams(_cmd[0]));
	else if (this->_cmd.size() >= 2)
	{
		if (is_channel == false && _user_exist(_cmd[1]) == false)
			return (this->_err_nosuchnick(_cmd[1]));
		else if (is_channel == false && (_cmd[1] != (*_users_it)->get_nickname()))
			return (this->_err_usersdontmatch());
		else if (is_channel == false && (_cmd[1] == (*_users_it)->get_nickname()) && _cmd.size() == 2)
			return (this->_rpl_umodeis(get_user_mode(*_users_it)));

		if (is_channel == true && this->_chan_exist(_cmd[1]) == false)
			return (this->_err_nosuchchannel(_cmd[1]));
		else
		{
			_chans_it = _chans.find(_cmd[1]);
			if (_chans_it != _chans.end())
			{
				cur_chan = (*this->_chans_it).second;
				bool chan_operator = is_operator((*_users_it)->get_nickname(), *cur_chan);
				if ((cur_chan->get_specific_mode(CHANMODE_p) == true
				|| cur_chan->get_specific_mode(CHANMODE_s) == true) && !chan_operator)
					return (this->_err_nosuchchannel(_cmd[1]));
			}
		}
		if (this->_cmd.size() == 2)
		{
			_rpl_channelmodeis();
			return (_rpl_creationtime());
		}
		else if (this->_cmd.size() >= 3)
		{
			String mode_change = "";
			ret = apply_mode(_cmd[1], &mode_change);
			if (ret == CHAN_MODE_MODIFIED)
				return (this->_cmd_mode(1, strip_orphan_sign(mode_change)));
			else if (ret == USER_MODE_MODIFIED)
				return (this->_cmd_mode(0, strip_orphan_sign(mode_change)));
		}
	}
	return (SUCCESS);
}
