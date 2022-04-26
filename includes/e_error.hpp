/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_error.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:00:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 21:04:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_ERROR_HPP
# define E_ERROR_HPP

# include <iostream>

enum e_error
{
	SUCCESS,
	ERROR_CONTINUE,
	ERROR_KILL,
	ERROR_BAD_PASSWD,
	ERROR_PING_REPLY,
	ERROR_PING_TIMEOUT,
	ERROR_REGISTRATION_TIMEOUT,
	ERROR_CLIENT_EXITED,
	ERROR_SERVER_EXITED
};

#endif
