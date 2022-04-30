# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:21:35 by ayzapata          #+#    #+#              #
#    Updated: 2022/04/30 20:23:40 by ayzapata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf
VERSION				= -std=c++98

CC					= c++
COMPILE_FLAG		= $(DEPS_FLAG) $(VERSION) -g -Wall -Werror -Wextra
DEPS_FLAG			= -MMD
INCLUDES_FLAG		= $(addprefix -I ,	$(INCLUDES_DIR) \
										$(CLASS_DIR) \
										$(DEFINES_DIR))
VALGRIND			= valgrind
VALGRIND_FLAG		= --leak-check=full --show-leak-kinds=all --track-fds=yes

INCLUDES_DIR		= includes/
CLASS_DIR			= $(INCLUDES_DIR)class/
DEFINES_DIR			= $(INCLUDES_DIR)defines/
OBJS_DIR			= objs/

SRCS_DIR			= srcs/
SOCKET_DIR			= $(SRCS_DIR)Socket/
SERVER_DIR			= $(SRCS_DIR)Server/
CLIENT_DIR			= $(SRCS_DIR)Client/
USER_DIR			= $(SRCS_DIR)User/
UTILS_DIR			= $(SRCS_DIR)Utils/
COMMAND_DIR			= $(SRCS_DIR)Command/
COMMAND_FCT_DIR		= $(COMMAND_DIR)Command_function/
MESSAGE_DIR			= $(SRCS_DIR)Message/
ERROR_MSG_DIR		= $(MESSAGE_DIR)error_msg/
REPLY_MSG_DIR		= $(MESSAGE_DIR)reply_msg/
CMD_MSG_DIR			= $(MESSAGE_DIR)cmd_msg/
HISTORICALNODE_DIR	= $(SRCS_DIR)HistoricalNode/
HISTORICAL_DIR		= $(SRCS_DIR)Historical/
DATA_DIR			= $(SRCS_DIR)Data/
CHANNEL_DIR			= $(SRCS_DIR)Channel/
STRING_DIR			= $(SRCS_DIR)String/

VPATH				= $(SRCS_DIR) $(SOCKET_DIR) $(SERVER_DIR) $(CLIENT_DIR)
VPATH				+=$(USER_DIR) $(UTILS_DIR) $(COMMAND_DIR) $(MESSAGE_DIR)
VPATH				+=$(HISTORICALNODE_DIR) $(HISTORICAL_DIR) $(COMMAND_FCT_DIR)
VPATH				+=$(DATA_DIR) $(ERROR_MSG_DIR) $(REPLY_MSG_DIR) $(CMD_MSG_DIR)
VPATH				+=$(CHANNEL_DIR) $(STRING_DIR)

ifndef ARG
	ARG = 6697 abc
endif

DEFAULT_FILES		= .operator .structor .member .accessor
SRCS				= $(addsuffix .cpp,				main \
													Exceptions \
													check_arguments \
													is_ \
													split \
													check_chan_name \
													print_error \
													print_server_name \
						$(addprefix Socket,			$(DEFAULT_FILES)) \
						$(addprefix Message,		$(DEFAULT_FILES)) \
													init_msg_error \
													\
													err_passwdmismatch \
													err_nonicknamegiven \
													err_nicknameinuse \
													err_unavailresource \
													err_restricted \
													err_erroneusnickname \
													err_needmoreparams \
													err_alreadyregistred \
													err_noorigin \
													err_nosuchserver \
													err_nosuchnick \
													err_nosuchchannel \
													err_usersdontmatch \
													err_chanoprivsneeded \
													\
													rpl_welcome \
													\
													cmd_pong \
													cmd_error \
													cmd_join \
													cmd_mode \
													cmd_topic \
													\
						$(addprefix Command,		$(DEFAULT_FILES)) \
													init_cmd_fct \
													topic \
													mode \
													nick \
													ping \
													user \
													pass \
													join \
													quit \
						$(addprefix Server,			$(DEFAULT_FILES)) \
						$(addprefix Client,			$(DEFAULT_FILES)) \
						$(addprefix User,			$(DEFAULT_FILES)) \
						$(addprefix HistoricalNode,	$(DEFAULT_FILES)) \
						$(addprefix Historical,		$(DEFAULT_FILES)) \
						$(addprefix Data,			$(DEFAULT_FILES)) \
						$(addprefix Channel,		$(DEFAULT_FILES)) \
						$(addprefix String,			$(DEFAULT_FILES) \
													.compare \
													.find \
													.rfind \
													.find_first_of \
													.find_last_of \
													.find_first_not_of \
													.find_last_not_of ) \
													init_case_off)
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

