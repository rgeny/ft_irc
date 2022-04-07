/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accessor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:00:29 by ayzapata          #+#    #+#             */
/*   Updated: 2022/04/07 18:28:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESSOR_HPP
#define ACCESSOR_HPP

#include <iostream>
#include <string>

template	< class T = std::string >
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

		T		get() const { return (this->_val); };
		void	set(T & val) { this->_val = val; };
};

template	< class T = std::string >
class Setter
{
	private:
		T	_val;
		Setter() {};


	public:
		Setter(T	value) : _val(value) {};
		Setter(Setter const & src) : _val(src.value) {};
		~Setter() {};
		Setter	& operator=(Setter const & rhs)
		{
			this->_val = rhs.get();
			return (*this);
		};

		void	set(T & val) { this->_val = val; };
};

template	< class T = std::string >
class Getter
{
	private:
		T	_val;
		Getter() {};


	public:
		Getter(T	value) : _val(value) {};
		Getter(Getter const & src) : _val(src.value) {};
		~Getter() {};
		Getter	& operator=(Getter const & rhs)
		{
			this->_val = rhs.get();
			return (*this);
		};

		T		get() const { return (this->_val); };
};

#endif
