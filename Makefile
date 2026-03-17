# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 12:03:20 by cescobio          #+#    #+#              #
#    Updated: 2026/03/17 11:52:39 by damiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS := -Werror -Wall -Wextra
PROGRAM = push_swap

SRC = main.c \
	bench.c \
	operations/push.c \
	operations/reverse_rotate.c \
	operations/rotate.c \
	operations/swap.c \
	parsing/bench_flag.c \
	parsing/error.c \
	parsing/parse_numbers.c \
	parsing/strategy_flag.c \
	sorting/adaptive_sort.c \
	sorting/select_algorithm.c \
	sorting/complex_sort.c \
	sorting/medium_sort.c \
	sorting/simple_sort.c \
	stack/add_node_back.c \
	stack/compute_disorder.c \
	stack/create_node.c \
	stack/init_stack.c \
	stack/print_stack.c \
	stack/free_stack.c \
	utils/strict_atoi.c \
	utils/ft_strncmp.c \
	utils/estimate_sqrt.c \
	validation/check_duplicated.c \
	validation/is_order.c \
	validation/is_valid_number.c
OBJ = $(SRC:.c=.o)

#shuf es un comando muy chungo, nos interesa para generar números aleatorios
#con las flags "-n" y "-i".
SHUF_FILE = args.txt #archivo donde se guardan.
SHUF_RANGE = 1-10000 #rango de números a elegir.
SHUF_AMOUNT = 2000 #cantidad de números final.
#Por defecto shuf elige números *sin repetir*.

#SRC = ""
#OUT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

shuf:
	shuf -i $(SHUF_RANGE) -n $(SHUF_AMOUNT) > $(SHUF_FILE)

#Estos comandos son copiados del PDF.
#En "args.txt" están los números generados por el comando shuf.
#Cada número pasa al programa como un argumento diferente.
default:
	./$(PROGRAM) $$(cat args.txt)

simple:
	./$(PROGRAM) --simple $$(cat args.txt)

medium:
	./$(PROGRAM) --medium $$(cat args.txt)

complex:
	./$(PROGRAM) --complex $$(cat args.txt)

adaptive:
	./$(PROGRAM) --adaptive $$(cat args.txt)

bench_simple:
	./$(PROGRAM) --simple --bench $$(cat args.txt)

bench_medium:
	./$(PROGRAM) --medium --bench $$(cat args.txt)

bench_complex:
	./$(PROGRAM) --complex --bench $$(cat args.txt)

bench_adaptive:
	./$(PROGRAM) --adaptive --bench $$(cat args.txt)

.PHONY: all clean fclean re shuf simple medium complex adaptive

#checker del PDF que no sé ni lo que hace
#checker:
#	./checker_linux $$(cat args.txt)
