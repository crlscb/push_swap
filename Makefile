# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 12:03:20 by cescobio          #+#    #+#              #
#    Updated: 2026/03/20 11:34:16 by damiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS := -Werror -Wall -Wextra
PROGRAM = push_swap

SRC = main.c \
	bench.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	swap.c \
	bench_flag.c \
	error.c \
	parse_numbers.c \
	strategy_flag.c \
	ft_split.c \
	complex_sort.c \
	medium_sort.c \
	simple_sort.c \
	add_node_back.c \
	select_algorithm.c \
	compute_disorder.c \
	create_node.c \
	init_stack.c \
	print_stack.c \
	free_stack.c \
	strict_atoi.c \
	ft_strncmp.c \
	estimate_sqrt.c \
	ft_strlcpy.c \
	check_duplicated.c \
	is_order.c \
	is_valid_number.c
OBJ = $(SRC:.c=.o)

#shuf es un comando muy chungo, nos interesa para generar números aleatorios
#con las flags "-n" y "-i".
SHUF_FILE = args.txt #archivo donde se guardan.
SHUF_RANGE = 1-10000 #rango de números a elegir.
SHUF_AMOUNT = 2000 #cantidad de números final.
#Por defecto shuf elige números *sin repetir*.

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf printf/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf printf/*.a

re: fclean all

.PHONY: all clean fclean re

#checker del PDF que no sé ni lo que hace
#checker:
#	./checker_linux $$(cat args.txt)
