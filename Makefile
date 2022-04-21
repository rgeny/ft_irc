# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:21:35 by ayzapata          #+#    #+#              #
#    Updated: 2022/04/23 01:37:16 by rgeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf
VERSION				= -std=c++98

CC					= c++
COMPILE_FLAG		= $(DEPS_FLAG) $(VERSION) -g#-Wall -Werror -Wextra
DEPS_FLAG			= -MMD
INCLUDES_FLAG		= -I$(INCLUDES_DIR)
VALGRIND			= valgrind
VALGRIND_FLAG		= --leak-check=full --show-leak-kinds=all --track-fds=yes

INCLUDES_DIR		= includes/
OBJS_DIR			= objs/
SRCS_DIR			= srcs/
SOCKET_DIR			= $(SRCS_DIR)Socket/
SERVER_DIR			= $(SRCS_DIR)Server/
CLIENT_DIR			= $(SRCS_DIR)Client/
USER_DIR			= $(SRCS_DIR)User/
UTILS_DIR			= $(SRCS_DIR)Utils/
COMMAND_DIR			= $(SRCS_DIR)Command/
MESSAGE_DIR			= $(SRCS_DIR)Message/
HISTORICALNODE_DIR	= $(SRCS_DIR)HistoricalNode/
HISTORICAL_DIR		= $(SRCS_DIR)Historical/

VPATH				= $(SRCS_DIR) $(SOCKET_DIR) $(SERVER_DIR) $(CLIENT_DIR)
VPATH				+=$(USER_DIR) $(UTILS_DIR) $(COMMAND_DIR) $(MESSAGE_DIR)
VPATH				+=$(HISTORICALNODE_DIR) $(HISTORICAL_DIR)

ifndef ARG
	ARG = 6697 abc
endif

DEFAULT_FILES		= .operator .structor .member .accessor
SRCS				= $(addsuffix .cpp,				main \
													Exceptions \
													check_arguments \
													is_ \
													split \
													case_proof\
						$(addprefix Socket,			$(DEFAULT_FILES)) \
						$(addprefix Server,			$(DEFAULT_FILES)) \
						$(addprefix Client,			$(DEFAULT_FILES)) \
						$(addprefix User,			$(DEFAULT_FILES)) \
						$(addprefix Command,		$(DEFAULT_FILES)) \
						$(addprefix Message,		$(DEFAULT_FILES)) \
						$(addprefix HistoricalNode,	$(DEFAULT_FILES)) \
						$(addprefix Historical,		$(DEFAULT_FILES)))
OBJS				= $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))
DEPS				= $(OBJS:.o=.d)

NAME				= ircserv
CLIENT				= client
TEST				= test

all					: new_dir $(NAME)

$(NAME)				: $(OBJS)
					$(CC) $(COMPILE_FLAG) $^ -o $@

$(OBJS_DIR)%.o		: %.cpp
					$(CC) $(COMPILE_FLAG) -c $< $(INCLUDES_FLAG) -o $@

new_dir				:
					$(NEW_DIR) $(OBJS_DIR)

install				:
					/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
					echo 'eval "$$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> "$$HOME/.bashrc"
					bash -c "brew install irssi"

uninstall			:
					/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/uninstall.sh)"
					rm -rf ~/.linuxbrew
					

valgrind			: all
					$(VALGRIND) $(VALGRIND_FLAG) ./$(NAME) $(ARG)

$(CLIENT)			:
					$(CC) client.cpp $(INCLUDES_FLAG) -o $@
					./$@ $(ARG)

$(TEST)				:
					$(CC) test.cpp -o $@
					./$@

clean				:
					$(DEL_DIR) $(OBJS_DIR)

fclean				: clean
					$(DEL_DIR) $(NAME) $(CLIENT) $(TEST)

re					:
					make fclean
					make

-include			$(DEPS)

.PHONY				: all clean fclean re client test

