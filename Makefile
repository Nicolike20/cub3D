# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nortolan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:57:19 by nortolan          #+#    #+#              #
#    Updated: 2023/03/27 12:46:30 by Vsavilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################
###   Program/s name/s   ###
############################

NAME = cub3D

LIBFT_NAME = libft.a

LMLX_NAME = libmlx.a

##############
###   OS   ###
##############

UNAME_S := $(shell uname -s)

##############################
###   Compiler and flags   ###
##############################

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT)/inc -I ./$(LMLX)

CFLAGS += -O3

#CFLAGS += -fsanitize=address -g3

MLX = -framework OpenGL -framework AppKit

#CFLAGS += -fsanitize=address -g3

#################
###   Paths   ###
#################

SRC_PATH = src

OBJ_PATH = obj

INC_PATH = inc

LIB_PATH = lib

LIBFT_PATH = libft

MLX_PATH = minilibx_macos

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
				parse_utils.c	check_map.c			textures.c

SRCS_WINDOW =	manage_window.c game_loop.c keys.c mlx_memory.c draw.c crosshire.c \
		mlx_functions.c minimap.c raycast.c player.c keys_move.c door.c

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

#######################
###   Create libs   ###
#######################

LIBFT =	$(LIB_PATH)/$(LIBFT_PATH)

LMLX = $(LIB_PATH)/$(MLX_PATH)

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

$(LIBFT_NAME):
	$(MAKE) all -sC $(LIBFT)
	cp -r $(addprefix $(LIBFT)/, $(LIBFT_NAME)) $(LIBFT_NAME)

$(LMLX_NAME):
	$(MAKE) all -sC $(LMLX)
	cp -r $(addprefix $(LMLX)/, $(LMLX_NAME)) $(LMLX_NAME)

######################
###   Compile .o   ###
######################

$(NAME): $(LMLX_NAME) $(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME) $(LMLX_NAME) $(LIBFT_NAME)

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

fclean: clean
	$(MAKE) fclean -sC $(LIBFT)
	$(MAKE) clean -sC $(LMLX)
	rm -rf $(NAME)
	rm $(LIBFT_NAME)
	rm $(LMLX_NAME)

re: fclean all

funsiona:
	-norminette $(INC_PATH)
	-norminette $(SRC_PATH)
	-norminette $(LIB_PATH)/$(LIBFT_PATH)

.PHONY: all clean fclean re sanitize funsiona
