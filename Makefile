NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -I 
ARC = ar rc
SRCS = ft_printf.c \
	   print_addr.c print_char.c print_hexa.c print_int.c print_str.c \
	   utils_1.c utils_2.c utoa.c utox.c ltox.c ft_itoa.c

OBJ = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	$(ARC) $(NAME) $(OBJ)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	
.PHONY: all clean fclean re
