# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:21:35 by ayzapata          #+#    #+#              #
#    Updated: 2022/04/05 19:39:33 by ayzapata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf
VERSION				= -std=c++98

CC					= c++
COMPILE_FLAG		= $(VERSION) -g -Wall -Werror -Wextra
DEPS_FLAG			= -MMD
INCLUDES_FLAG		= -I $(INCLUDES_DIR)

INCLUDES_DIR		= includes/
OBJS_DIR			= objs/
SRCS_DIR			= srcs/

VPATH				= $(SRCS_DIR)

SRCS				= \
					Exceptions.cpp \
					User.cpp \
					Channel.cpp \
					Message.cpp \
					check_arguments.cpp \
					ircserv.cpp \
					main.cpp

OBJS				= $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))
DEPS				= $(OBJS:.o=.d)

NAME				= ircserv


all					: $(OBJS) $(NAME)
					
$(NAME)		: $(SRCS)
					$(CC) $(COMPILE_FLAG) $^ -o $@

$(OBJS_DIR)%.o		: %.cpp
					$(NEW_DIR) $(OBJS_DIR)
					$(CC) $(COMPILE_FLAG) $(DEPS_FLAG) -c $< $(INCLUDES_FLAG) -o $@

clean				:
					$(DEL_DIR) $(OBJS_DIR)

fclean				: clean
					$(DEL_DIR) $(NAME)

re					: fclean all

-include			$(DEPS)

.PHONY				: all clean fclean re