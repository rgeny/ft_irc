/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:55:34 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/16 23:22:01 by abesombe         ###   ########.fr       */
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

String Command::get_user_mode(User* target_user)
{
	String user_mode;
	user_mode = user_mode 
				+ (target_user->get_specific_mode(USERMODE_i) ? "i" : "")
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

int Command::apply_mode(String target, String *mode_change)
{
	size_t 	size_modestr = _cmd[2].length();
	size_t 	i = 0;
	Channel* cur_chan = (*this->_chans_it).second;
	User* cur_user = (*_users_it);
	String err_msg;
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
		User *target_user = NULL;
		bool is_channel = has_begin_hashtag(this->_cmd[1]);
		std::cout << "char[" << i << "] is being analyzed for mode changes\n";
		std::cout << "arg_num: " << arg_num << std::endl;
		
		char mode_char = _cmd[2][i];
		if (mode_type(mode_char)) // MODE EXISTS
		{
			std::cout << "char is a " << mode_char << "\n";
			
			if (!has_begin_hashtag(this->_cmd[1]) && mode_char == 'o' && arg_num > _cmd.size() - 1)
			{
				err_msg = String("You must specify a parameter for the ") + (mode_char == 'o' ? "op" : "voice") + String(" mode. Syntax: <nick>.");
				this->_err_needmoreparams(err_msg);
				continue;
			}
				// return (_err_noprivileges("Permission Denied - Only operators may set user mode o"));
			else if (!has_begin_hashtag(this->_cmd[1]) && std::string("asOv").find(mode_char) != std::string::npos && _cmd.size() == 3)
				return (_err_umodeunknownflag(String(1, mode_char), "is not a recognised user mode"));

			bool previous_state = false;
			if (mode_type(mode_char) == 1 && !is_channel) // USER MODE
				update_user_mode(previous_state, modified, i, add, target, mode_change);
			else if (mode_type(mode_char) && is_channel) // CHANNEL MODE
			{
				Channel::CHAN_BAN_LIST *chan_ban_list = NULL;
				std::cout << "Nb of channels: " << _chans.size() << std::endl;
				String nickname = (*_users_it)->get_nickname();
				bool chan_operator = is_operator(nickname, *cur_chan);
				if ((_chans.size() > 0 && chan_operator == true) || (mode_char == 'b'))
				{
					if ((mode_char == 'o' || mode_char == 'v') && arg_num <= _cmd.size() - 1)
					{
						std::cout << "Update modes 'o' ou 'v' sur une target" << std::endl;
						if (this->_user_exist(_cmd[arg_num]) == false)
							return (_err_nosuchnick(_cmd[arg_num]));
						if (user_exist_in_chan(*cur_chan, _cmd[arg_num]) == false)
							return (_err_usernotinchannel(_cmd[arg_num], cur_chan->get_chan_name()));
						target_user = _get_user(_cmd[arg_num]);
						if (target_user->get_chan_usermode().size() > 0)
							previous_state = false;
						else if (target_user->get_chan_usermode_vec(_cmd[1]).size() > 0)
							previous_state = target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(mode_char)];
						target_user->set_chan_usermode(_cmd[1], usermodes.find(mode_char), add);

						if (previous_state != target_user->get_chan_usermode_vec(_cmd[1])[usermodes.find(mode_char)])
						{
							modified = CHAN_MODE_MODIFIED;
							*mode_change = *mode_change + char_to_String(mode_char);
							std::cout << "CHAN MODE UPDATED\n";
						}
						arg_num++;
					}
					else if ((mode_char == 'o' || mode_char == 'v') && arg_num > _cmd.size() - 1)
					{
						err_msg = String("You must specify a parameter for the ") + (mode_char == 'o' ? "op" : "voice") + String(" mode. Syntax: <nick>.");
						this->_err_needmoreparams(err_msg);
						i++;
						continue;
					}
					else
					{
						bool is_key_set = cur_chan->get_specific_mode(CHANMODE_k);
						bool is_limit_set = cur_chan->get_specific_mode(CHANMODE_l);
						chan_ban_list = &(*_chans_it).second->get_chan_ban_list();

						// MODE "k"
						if (mode_char == 'k' && add == true && is_key_set == false)
						{ 
							if (arg_num > _cmd.size() - 1)
								return (this->_err_needmoreparams("k * You must specify a parameter for the key mode. Syntax: <key>."));
							cur_chan->set_key(_cmd[arg_num]);
							arg_num++;
						}
						else if (mode_char == 'k' && add == true && is_key_set == true)
						{
							i++;
							arg_num++;
							continue;	
						}
						else if (mode_char == 'k' && add == false && is_key_set == true)
						{
							arg_num++;
							cur_chan->set_key("");
						}
						else if (mode_char == 'k' && add == false && is_key_set == false)
						{
							i++;
							arg_num++;
							continue;
						}

						// MODE "l"
						
						if (mode_char == 'l' && add == true && is_limit_set == false)
						{
							if (arg_num > _cmd.size() - 1)
							{
								this->_err_needmoreparams("l * You must specify a parameter for the limit mode. Syntax: <limit>.");
								arg_num++;
								i++;
								continue;
							}
							cur_chan->set_limit(_cmd[arg_num]);
							arg_num++;
						}
						else if (mode_char == 'l' && add == true && is_limit_set == true)
						{
							i++;
							arg_num++;
							continue;	
						}
						else if (mode_char == 'l' && add == false && is_limit_set == true)
						{
							cur_chan->set_limit(0);
							arg_num++;
						}
						else if (mode_char == 'l' && add == false && is_limit_set == false)
						{
							i++;
							arg_num++;
							continue;
						}

						// MODE "b"
						size_t count_mode_letters = 0;
						for (size_t i = 0 ; i < _cmd[2].size(); i++)
						{
							if (mode_char != '+' && mode_char != '-')
								count_mode_letters++;
						}
							
						if (mode_char == 'b' && add == true && (arg_num > _cmd.size() - 1))
						{
							if (chan_ban_list->size() > 0)
								_rpl_banlist();
							if (count_mode_letters > 1)
								_rpl_endofbanlist();
							else
								return (_rpl_endofbanlist());
						}
						else if (mode_char == 'b' && add == true && arg_num <= _cmd.size() - 1)
						{
							if (!chan_operator)
							    return (_err_chanoprivsneeded());
							if (chan_ban_list->size() >= CHAN_BAN_LIST_MAX_SIZE)
								return (_err_banlistfull());
							if (chan_ban_list->find(_cmd[arg_num]) == chan_ban_list->end())
							{
								Channel::PAIR_BAN_CREATORNAME_TIME bpair = std::make_pair(*_users_it, time(0));
								chan_ban_list->insert(std::make_pair(_cmd[arg_num], bpair));
								_cmd[arg_num] = _cmd[arg_num] + "!*@*";
							}
							arg_num++;
						}
						else if (mode_char == 'b' && add == false && arg_num <= _cmd.size() - 1)
						{
							String needle_nick;
							if (_cmd[arg_num].substr(_cmd[arg_num].length() - 4) == "!*@*")
							{
								needle_nick = _cmd[arg_num].substr(0, _cmd[arg_num].length() - 4);
								if (!chan_operator)
									return (_err_chanoprivsneeded());
								chan_ban_list->erase(needle_nick);
								modified = CHAN_MODE_MODIFIED;
								*mode_change = *mode_change + char_to_String(mode_char);
								arg_num++;
							}
						}


						previous_state = cur_chan->get_specific_mode(chanmodes.find(mode_char));

						_chans[target]->set_specific_mode(chanmodes.find(mode_char), add);
						if (previous_state != cur_chan->get_specific_mode(chanmodes.find(mode_char)))
						{
							modified = CHAN_MODE_MODIFIED;
							*mode_change = *mode_change + char_to_String(mode_char);
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
			_err_umodeunknownflag(char_to_String(mode_char), ":Unknown MODE flag");
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
		return (this->_err_needmoreparams());
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
