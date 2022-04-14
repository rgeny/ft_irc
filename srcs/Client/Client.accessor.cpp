/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.accessor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:35:46 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/14 15:19:36 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Socket&	Client::get_socket(void)
{
    return (this->_socket);
}

User&	Client::get_user(void)
{
    return (this->_user);
}