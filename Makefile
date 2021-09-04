##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

NAME	=	bsq

SRC	=	$(wildcard src/*.c) \
		$(wildcard src/input_file/*.c) \
		$(wildcard src/algo/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -g3 -O3

INCPATH = -I./include

.c.o:
	@gcc $(CFLAGS) $(INCPATH) -c $< -o $@

all:	$(OBJ)
	@make --no-print-directory -C lib re
	@gcc -o $(NAME) $(OBJ) lib/libmy

clean:
	@make --no-print-directory -C lib/ clean
	@rm -f $(OBJ)

fclean: clean
	@make --no-print-directory -C lib/ fclean
	rm -f $(NAME)

re: fclean all
