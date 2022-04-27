/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:36:35 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/27 20:42:31 by rgeny            ###   ########.fr       */
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
# include "String.hpp"

int		print_error	(String err);

bool	is_special	(char c);
bool	is_hexdigit	(char c);
bool	is_number	(const String & str);

std::vector<String>		split	(String str
								,String delimiter);
String				case_proof	(String str);
bool 					check_chan_name(String name);
#endif
