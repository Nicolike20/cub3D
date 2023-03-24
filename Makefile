# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nortolan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:57:19 by nortolan          #+#    #+#              #
#    Updated: 2023/03/23 16:58:41 by nortolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################
###   Program/s name/s   ###
############################

NAME = cub3D


##############
###   OS   ###
##############

UNAME_S := $(shell uname -s)

##############################
###   Compiler and flags   ###
##############################

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS += -I ./$(INC_PATH)

#CFLAGS += -O3

#CFLAGS += -fsanitize=address -g3

#################
###   Paths   ###
#################

SRC_PATH = src

OBJ_PATH = obj

INC_PATH = inc

LIB_PATH = lib

################
###   Libs   ###
################

LFT_NAME = libft.a
LFT_DIR = $(LIB_PATH)/libft
LFT = $(LFT_DIR)/$(LFT_NAME)

LMLX_NAME = libmlx.a
ifeq ($(UNAME_S),Linux)
LMLX_DIR = $(LIB_PATH)/minilibx_linux
endif
ifeq ($(UNAME_S),Darwin)
LMLX_DIR = $(LIB_PATH)/minilibx_macos
endif
LMLX = $(LMLX_DIR)/$(LMLX_NAME)
LDFLAGS = -L ./$(LFT_DIR) -lft

ifeq ($(UNAME_S),Darwin)
LDFLAGS += -L ./$(LMLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME_S),Linux)
LDFLAGS += -L ./$(LMLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

CFLAGS += -I ./$(LFT_DIR)/inc -I ./$(LMLX_DIR)

# -L/usr/lib

#CFLAGS += -fsanitize=address -g3

#######################
###   Directories   ###
#######################

SRC_DIR_PARSER = parser
SRC_DIR_WINDOW = window
SRC_DIR_UTILS = utils

OBJ_DIR_ALL =	$(SRC_DIR_PARSER) \
		$(SRC_DIR_WINDOW) \
		$(SRC_DIR_UTILS) \

OBJ_DIR = $(addprefix $(OBJ_PATH)/, $(OBJ_DIR_ALL))

########################
###   Source items   ###
########################

SRCS_MAIN =	main.c

SRCS_PARSER =	parse.c			get_lines.c			get_id.c\
				parse_utils.c	check_map.c			textures.c		colors.c

SRCS_WINDOW =	manage_window.c game_loop.c keys.c mlx_memory.c draw.c crosshire.c \
		mlx_functions.c minimap.c raycast.c player.c keys_move.c

SRCS_UTILS = error.c init.c

SRCS_NAME =	$(SRCS_MAIN) \
		$(addprefix $(SRC_DIR_PARSER)/, $(SRCS_PARSER)) \
		$(addprefix $(SRC_DIR_WINDOW)/, $(SRCS_WINDOW)) \
		$(addprefix $(SRC_DIR_UTILS)/, $(SRCS_UTILS))

######################
###   Make rules   ###
######################

MAKE = make

##########################
###   Create objects   ###
##########################

OBJS_NAME = $(SRCS_NAME:%.c=%.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

#################################
###   Rules can be executed   ###
#################################

all: $(NAME)

#######################
###   Objects dir   ###
#######################

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR): | $(OBJ_PATH)
	mkdir -p $(OBJ_DIR) 2> /dev/null

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

########################
###   Compile libs   ###
########################

$(LFT):
	$(MAKE) all -sC $(LFT_DIR)

$(LMLX):
	$(MAKE) all -sC $(LMLX_DIR)

######################
###   Compile .o   ###
######################

$(NAME): $(LMLX) $(LFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

############################
###   Sanitize (Linux)   ###
############################
ifeq ($(UNAME_S),Linux)
sanitize: CFLAGS += -lreadline -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
endif
ifeq ($(UNAME_S),Darwin)
sanitize: CFLAGS += -pedantic -g3 -fsanitize=address
endif
sanitize: $(NAME)

#######################
###   Other rules   ###
#######################

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) fclean -sC $(LFT_DIR)
	$(MAKE) clean -sC $(LMLX_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

funsiona:
	-norminette $(INC_PATH)
	-norminette $(SRC_PATH)
	-norminette $(LFT_DIR)

.PHONY: all clean fclean re sanitize funsiona
