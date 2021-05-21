# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 22:09:18 by tkomatsu          #+#    #+#              #
#    Updated: 2021/05/21 16:11:16 by tkomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
INCLUDE = -I includes
LIBS = ar -rc
DEBUG_FLAGS = -g3

CTYPE_DIR = ctype/

CTYPE_FILES = ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isblank.c \
			  ft_iscntrl.c \
			  ft_isdigit.c \
			  ft_islower.c \
			  ft_isprint.c \
			  ft_isspace.c \
			  ft_isupper.c \
			  ft_tolower.c \
			  ft_toupper.c

CTYPE_SRCS = $(addprefix $(CTYPE_DIR), $(CTYPE_FILES))

HASH_DIR = hash/

HASH_FILES = hash.c

HASH_SRCS = $(addprefix $(HASH_DIR), $(HASH_FILES))

IO_DIR = io/

IO_FILES =  ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			get_next_line.c \
			reset_gnl.c

IO_SRCS = $(addprefix $(IO_DIR), $(IO_FILES))

LIST_DIR = list/

LIST_FILES = ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstat.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstmerge.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstsort.c

LIST_SRCS = $(addprefix $(LIST_DIR), $(LIST_FILES))

MEM_DIR = mem/

MEM_FILES = ft_bzero.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c

MEM_SRCS = $(addprefix $(MEM_DIR), $(MEM_FILES))

STDLIB_DIR = stdlib/

STDLIB_FILES = ft_atof.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_strtol.c

STDLIB_SRCS = $(addprefix $(STDLIB_DIR), $(STDLIB_FILES))

STR_DIR = string/

STR_FILES = ft_free_split.c \
			ft_parse_esc.c \
			ft_split.c \
			ft_strcasecmp.c \
			ft_strcat.c \
			ft_strchr.c  \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strisf.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncasecmp.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtok.c \
			ft_strtok_r.c \
			ft_strtrim.c \
			ft_substr.c

STR_SRCS = $(addprefix $(STR_DIR), $(STR_FILES))

SRC_DIR = srcs/

SRC_FILES = $(CTYPE_SRCS) \
			$(HASH_SRCS) \
			$(IO_SRCS) \
			$(LIST_SRCS) \
			$(MEM_SRCS) \
			$(STDLIB_SRCS) \
			$(STR_SRCS)

OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBS) $(NAME) $(OBJS)
	@echo "$(_END)\nCompiled libft"

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 
	@printf "$(_GREEN)█"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(CTYPE_DIR)
	@mkdir -p $(OBJ_DIR)$(HASH_DIR)
	@mkdir -p $(OBJ_DIR)$(IO_DIR)
	@mkdir -p $(OBJ_DIR)$(LIST_DIR)
	@mkdir -p $(OBJ_DIR)$(MEM_DIR)
	@mkdir -p $(OBJ_DIR)$(PTF_DIR)
	@mkdir -p $(OBJ_DIR)$(STDLIB_DIR)
	@mkdir -p $(OBJ_DIR)$(STR_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(NAME) $(OBJ_DIR)

re: fclean $(NAME)

debug: CFLAGS += -fsanitize=address $(DEBUG_CFLAGS)
debug: re

leak: CFLAGS += $(DEBUG_CFLAGS)
leak: re

test: debug
	@$(CC) $(CFLAGS) $(INCLUDE) -g3 -L. -lft -o grademe test/main.c
	@./grademe
	@rm grademe

.PHONY	: all clean fclean re
