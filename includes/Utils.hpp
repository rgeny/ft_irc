/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:36:35 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/10 17:22:32 by rgeny            ###   ########.fr       */
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
# include <queue>

# include "colors.hpp"
# include "String.hpp"

class String;

int		print_error	(String err);

bool	is_special	(char c);
bool	is_hexdigit	(char c);
bool	is_number	(const String & str);
bool	is_mask		(char c);

std::vector<String>		split	(String str
								,String delimiter);
std::queue<String>		qsplit	(String str
								,String delimiter);
String					case_proof	(String str);
bool					check_chan_name(String name);
bool					has_begin_hashtag(String name);
void					print_server_name(void);

#endif
