/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:16:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 18:32:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_join	(void)
{
//	Message reply;

	if ((*this->_msgs_it).size() < 2)
		return (this->_err_needmoreparams());
//	{
//		reply.add_arg(cmd[0]);
//		std::string final_msg = reply.forge("127.0.0.1", ERR_NEEDMOREPARAMS);
//		this->_client->add_to_queue(final_msg);
//		return (-1);
//	}
	// else
	// {
	// 	if (chans.count(cmd[1]) == 1)
	// }
	return (SUCCESS);
}
