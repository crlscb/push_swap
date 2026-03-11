# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 12:03:20 by cescobio          #+#    #+#              #
#    Updated: 2026/03/11 15:30:04 by cescobio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra
PROGRAM = push_swap

SRC = main.c parsing.c stack_utils.c operations/swap.c operations/push.c operations/rotate.c operations/reverse_rotate.c algorithms/simple_sort.c
OBJ = $(SRC:.c=.o)

#shuf es un comando muy chungo, nos interesa para generar números aleatorios
#con las flags "-n" y "-i".
SHUF_FILE = args.txt #archivo donde se guardan. 
SHUF_RANGE = 1-100 #rango de números a elegir.
SHUF_AMOUNT = 10 #cantidad de números final.
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
simple:
	./$(PROGRAM) $$(cat args.txt)

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