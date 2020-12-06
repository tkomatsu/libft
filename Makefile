NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
LIBS = ar -rc

SRC_DIR = srcs/

FILES =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strchr.c  \
		ft_strrchr.c \
		ft_atoi.c \
		ft_strnstr.c \
		ft_memset.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstiter.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstmap.c \
		ft_lstsort.c \
		get_next_line.c \
		ft_isspace.c \
		ft_strisf.c \
		ft_atof.c \
		ft_puterr.c \
		ft_free.c

SRCS = $(addprefix $(SRC_DIR), $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBS) $(NAME) $(OBJS)
	@echo "Compiled libft"

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	@rm -f $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean $(NAME)

.PHONY	: all clean fclean re
