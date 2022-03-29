# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:54:47 by rgeny             #+#    #+#              #
#    Updated: 2022/03/29 16:11:11 by rgeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf

CC					= c++
COMPILE_FLAG		= $(DEPS_FLAG) -std=c++98 -Wall -Werror -Wextra
DEPS_FLAG			= -MMD
INCLUDES_FLAG		= -I$(INCLUDES_DIR)

INCLUDES_DIR		= includes/
CLASS_DIR			= class/
OBJS_DIR			= objs/
SRCS_DIR			= srcs/

VPATH				= $(SRCS_DIR)

SRCS				= $(addsuffix .cpp,		main)
OBJS				= $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))
DEPS				= $(OBJS:.o=.d)

NAME				= ircserv

all					: $(NAME)

$(NAME)				: $(OBJS)
					$(CC) $(COMPILE_FLAG) $^ -o $@

$(OBJS_DIR)%.o		: %.cpp
					$(NEW_DIR) $(OBJS_DIR)
					$(CC) $(COMPILE_FLAG) -c $< $(INCLUDES_FLAG) -o $@

install				:
					/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
					echo 'eval "$$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> "$$HOME/.bashrc"
					bash -c "brew install irssi"

uninstall			:
					/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/uninstall.sh)"
					rm -rf ~/.linuxbrew
					

clean				:
					$(DEL_DIR) $(OBJS_DIR)

fclean				: clean
					$(DEL_DIR) $(NAME)

re					: fclean all

-include			$(DEPS)

.PHONY				: all clean fclean re
