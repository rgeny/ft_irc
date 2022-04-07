/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accessor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:00:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/05 16:15:04 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESSOR_HPP
#define ACCESSOR_HPP

#include <iostream>
#include <string>

template < class T = std::string >
class Accessor
{
	private:
		T	_val;
		Accessor() {};

	public:
		Accessor(T	value) : _val(value) {};
		Accessor(Accessor const & src) : _val(src.value) {};
		~Accessor() {};
		Accessor	& operator=(Accessor const & rhs)
		{
			this->_val = rhs.get();
			return (*this);
		};

		T		get(void) const { return (this->_val); };
		void	set(T & val) { this->_val = val; };
};

#endif
