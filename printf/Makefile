NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = 	ft_printf.c \
		ft_format_c.c \
		ft_format_d.c \
		ft_format_upd.c \
		ft_format_escape.c \
		ft_format_p.c \
		ft_format_s.c \
		ft_format_u.c \
		ft_format_x.c \
		ft_putnbr_hex.c \
		ft_handleformat.c \
		ft_printparam.c \
		ft_count_digits.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

test:
	cc *.c -o a.out -g3

re: fclean all

.PHONY: all clean fclean re
