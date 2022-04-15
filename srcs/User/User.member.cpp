/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.member.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:02:03 by abesombe          #+#    #+#             */
/*   Updated: 2022/04/15 17:34:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

std::string User::fci(void){
    return(nickname.get() + "!" + username.get() + "@" + hostname.get());
}