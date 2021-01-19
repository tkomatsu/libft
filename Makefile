NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I includes
LIBS = ar -rc

CTYPE_DIR = ctype/

CTYPE_FILES = ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_isspace.c \
			  ft_tolower.c \
			  ft_toupper.c

CTYPE_SRCS = $(addprefix $(CTYPE_DIR), $(CTYPE_FILES))

IO_DIR = io/

IO_FILES =  ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_puterr.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			get_next_line.c

IO_SRCS = $(addprefix $(IO_DIR), $(IO_FILES))

LIST_DIR = list/

LIST_FILES = ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
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

PTF_DIR = printf/

PTF_FILES = ft_getattribute.c \
			ft_isconvert.c \
			ft_isflag.c \
			ft_isnotformat.c \
			ft_itoc.c \
			ft_numlen.c \
			ft_printf.c \
			ft_putconvert.c \
			ft_putfmtc.c \
			ft_putfmtdi.c \
			ft_putfmtp.c \
			ft_putfmtpercent.c \
			ft_putfmts.c \
			ft_putfmtux.c \
			ft_putformat.c \
			ft_putintpad.c \
			ft_putintpre.c \
			ft_putpad.c

PRINTF_SRCS = $(addprefix $(PTF_DIR), $(PTF_FILES))

STDLIB_DIR = stdlib/

STDLIB_FILES = ft_atof.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_free.c \
				ft_itoa.c

STDLIB_SRCS = $(addprefix $(STDLIB_DIR), $(STDLIB_FILES))

STR_DIR = string/

STR_FILES = ft_free_split.c \
			ft_split.c \
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
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c

STR_SRCS = $(addprefix $(STR_DIR), $(STR_FILES))

SRC_DIR = srcs/

FILES = $(CTYPE_SRCS) $(ENV_SRCS) $(IO_SRCS) $(LIST_SRCS) $(MEM_SRCS) $(PTF_SRCS) $(STDLIB_SRCS) $(STR_SRCS)

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
