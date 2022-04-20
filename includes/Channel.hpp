/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:14:15 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 16:16:33 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <iostream>
#include <string>

#include "Accessor.hpp"

class Channel
{
	private:
		Channel();
	
	public:
		Accessor<std::string>	name;
		Accessor<std::string>	topic;
		Accessor<std::string>	mode;
		Accessor<std::string>	password;
		Accessor<size_t>		limit;
		Accessor<time_t>		creation;

		Channel(std::string const &	name,
				std::string const & topic,
				std::string const & mode,
				std::string const & password,
				std::size_t limit);
		Channel( Channel const & src);
		Channel & operator=(Channel const & rhs);
		~Channel();

};

std::ostream&	operator<<( std::ostream& o, Channel const & instance);

#endif
