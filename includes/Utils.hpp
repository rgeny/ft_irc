/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:36:35 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/26 18:29:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <locale>
# include <vector>
# include <string>
# include <cerrno>
# include <cstring>
# include <cstdlib>
# include "colors.hpp"

int		print_error	(std::string err);

bool	is_special	(char c);
bool	is_hexdigit	(char c);
bool	is_number	(const std::string & str);

std::vector<std::string>	split	(std::string str
									,std::string delimiter);
std::string					case_proof	(std::string str);
bool 						check_chan_name(std::string name);
#endif
