/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:14:15 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/13 11:51:13 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <iostream>
# include <string>
# include <map>

# include "Accessor.hpp"

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
