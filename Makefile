NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -I 
ARC = ar rcs
SRCS = ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	   ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	   ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	   ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	   ft_printf.c \
	   print_addr.c print_char.c print_hexa.c print_int.c print_str.c \
	   utils.c utoa.c utox.c ltox.c

OBJ = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(ARC) $(NAME) $(OBJ)

%.o:%.c libft.h ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
