/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:16:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/12 14:20:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_HPP
# define STRING_HPP
# include <sstream>
# define OUT_OF_RANGE(a, b) std::string("String::compare: pos (which is ") \
									+ a \
									+ ") > this->size() (which is " \
									+ b \
									+ ")"

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <cstring>

# include "Utils.hpp"

class String
	:public std::string
{
	public:
		String		(void);
		String		(const String & str);
		String		(const String & str
					,size_t pos
					,size_t len = std::string::npos);
		String		(const std::string & str);
		String		(const char * s);
		String		(const char * s
					,size_t n);
		String		(size_t n
					,char c);
		template <class InputIterator>
		String		(InputIterator first
					,InputIterator last)
			:std::string(first, last)
		{
			std::cout	<< "String range constructor."
						<< std::endl;
		}
		~String		(void);

		int		compare	(const String & str) const;
		int		compare	(size_t pos
						,size_t len
						,const String & str) const;
		int		compare (size_t pos
						,size_t len
						,const String & str
						,size_t subpos
						,size_t sublen) const;
		int		compare (const char * s) const;
		int		compare	(size_t pos
						,size_t len
						,const char * s) const;
		int		compare (size_t pos
						,size_t len
						,const char * s
						,size_t n) const;

		size_t	find	(const std::string & str) const;
		size_t	find	(const String & str
						,size_t pos = 0) const;
		size_t	find	(const char * s
						,size_t pos = 0) const;
		size_t	find	(const char * s
						,size_t pos
						,size_t n) const;
		size_t	find	(char c
						,size_t pos = 0) const;

		size_t	rfind	(const String & str
						,size_t pos = npos) const;
		size_t	rfind	(const char * s
						,size_t pos = npos) const;
		size_t	rfind	(const char * s
						,size_t pos
						,size_t n) const;
		size_t	rfind	(char c
						,size_t pos = npos) const;

		size_t	find_first_of	(const String & str
								,size_t pos = 0) const;
		size_t	find_first_of	(const char * s
								,size_t pos = 0) const;
		size_t	find_first_of	(const char * s
								,size_t pos
								,size_t n) const;
		size_t	find_first_of	(char c
								,size_t pos = 0) const;

		size_t	find_last_of	(const String & str
								,size_t pos = npos) const;
		size_t	find_last_of	(const char * s
								,size_t pos = npos) const;
		size_t	find_last_of	(const char * s
								,size_t pos
								,size_t n) const;
		size_t	find_last_of	(char c
								,size_t pos = npos) const;
		
		size_t	find_first_not_of	(const String & str
									,size_t pos = 0) const;
		size_t	find_first_not_of	(const char * s
									,size_t pos = 0) const;
		size_t	find_first_not_of	(const char * s
									,size_t pos
									,size_t n) const;
		size_t	find_first_not_of	(char c
									,size_t pos = 0) const;

		size_t	find_last_not_of	(const String & str
									,size_t pos = npos) const;
		size_t	find_last_not_of	(const char * s
									,size_t pos = npos) const;
		size_t	find_last_not_of	(const char * s
									,size_t pos
									,size_t n) const;
		size_t	find_last_not_of	(char c
									,size_t pos = npos) const;

	private:
		typedef std::vector<unsigned char>	CASE_OFF_TYPE;
		static CASE_OFF_TYPE	 			_case_off;

		static CASE_OFF_TYPE	_init_case_off	(void);
		unsigned char			_cast	(char c) const;
		std::string				_out_of_range	(size_t pos
												,size_t this_size) const;
		bool					_is_valid_name	(size_t i
												,size_t len
												,const String & str
												,size_t j
												,size_t & k
												,size_t sublen
												,size_t & l) const;
};
bool 	operator==	(const String & lhs
					,const String & rhs);
bool 	operator==	(const char * lhs
					,const String & rhs);
bool 	operator==	(const String & lhs
					,const char * rhs);

bool 	operator!=	(const String & lhs
					,const String & rhs);
bool 	operator!=	(const char * lhs
					,const String & rhs);
bool 	operator!=	(const String & lhs
					,const char * rhs);

bool 	operator<	(const String & lhs
					,const String & rhs);
bool 	operator<	(const char * lhs
					,const String & rhs);
bool 	operator<	(const String & lhs
					,const char * rhs);

bool 	operator<=	(const String & lhs
					,const String & rhs);
bool 	operator<=	(const char * lhs
					,const String & rhs);
bool 	operator<=	(const String & lhs
					,const char * rhs);

bool 	operator>	(const String & lhs
					,const String & rhs);
bool 	operator>	(const char * lhs
					,const String & rhs);
bool 	operator>	(const String & lhs
					,const char * rhs);

bool 	operator>=	(const String & lhs
					,const String & rhs);
bool 	operator>=	(const char * lhs
					,const String & rhs);
bool 	operator>=	(const String & lhs
					,const char * rhs);

#endif

