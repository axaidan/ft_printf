NAME = libftprintf.a
LIBFT_FLD = libft/
LIBFT = $(LIBFT_FLD)libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -I 
ARC = ar rcsT
SRCS = ft_printf.c \
	   print_addr.c print_char.c print_hexa.c print_int.c print_str.c \
	   utils.c utoa.c utox.c ltox.c

OBJ = $(SRCS:.c=.o)

all:	$(NAME)

$(LIBFT): break_implicit_rule
	make -C $(LIBFT_FLD)

$(NAME):	$(LIBFT) $(OBJ)
	$(ARC) $(NAME) $(LIBFT) $(OBJ)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_FLD) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re:	fclean all
	

break_implicit_rule:


.PHONY: all clean fclean re
