##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

NAME	=	libmy

SRC	= $(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -g3 -O3

INCPATH	= -I./../include

.c.o:
	@gcc $(CFLAGS) $(INCPATH) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	ar crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
