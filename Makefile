# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nortolan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:57:19 by nortolan          #+#    #+#              #
#    Updated: 2023/03/07 18:01:41 by nortolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################
###   Program/s name/s   ###
############################

NAME = cub3D

LIBFT_NAME = libft.a

##############
###   OS   ###
##############

UNAME_S := $(shell uname -s)

##############################
###   Compiler and flags   ###
##############################

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS += -I ./$(INC_PATH) -I ./$(LIB_PATH)/inc

#CFLAGS += -fsanitize=address -g3

#################
###   Paths   ###
#################

SRC_PATH = src

OBJ_PATH = obj

INC_PATH = inc

LIB_PATH = libft

#######################
###   Directories   ###
#######################

SRC_DIR_PARSER = parser

OBJ_DIR_ALL =	$(SRC_DIR_PARSER) \

OBJ_DIR = $(addprefix $(OBJ_PATH)/, $(OBJ_DIR_ALL))

########################
###   Source items   ###
########################

SRCS_MAIN =	main.c

SRCS_PARSER =	parse.c get_lines.c parse_utils.c check_map.c

SRCS_NAME =	$(SRCS_MAIN) \
		$(addprefix $(SRC_DIR_PARSER)/, $(SRCS_PARSER)) \

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

## Object dir

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR): | $(OBJ_PATH)
	mkdir -p $(OBJ_DIR)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

########################
###   Compile libs   ###
########################

$(LIBFT_NAME):
	$(MAKE) all -sC $(LIB_PATH)
	cp -r $(addprefix $(LIB_PATH)/, $(LIBFT_NAME)) $(LIBFT_NAME)

######################
###   Compile .o   ###
######################

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_NAME)

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
	rm -rf $(LIBFT_NAME)

fclean: clean
	$(MAKE) fclean -sC $(LIB_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize
