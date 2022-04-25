/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:45:16 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/25 12:56:59 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_HPP
# define ERROR_MSG_HPP

# define PORT_MIN 1024
# define PORT_MAX 65535

# define ERROR_NBR_OF_ARGS	"Error: wrong number of arguments. It should be ./ircserv <port> <password>"
# define ERROR_PORT_ARG		"Error: the port argument has not the right format"
# define ERROR_PASSWD_ARG	"Error: the password argument has not the right format"
# define ERROR_OPEN_SOCKET	"Error: opening socket: "
# define ERROR_ACCEPT		"Error: accept_failed: "
# define ERROR_RECV			"Error: recv_failed: "
# define ERROR_SEND			"Error: send_failed: "

#endif

