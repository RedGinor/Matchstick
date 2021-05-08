##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

SRC	=	src/main.c			\
		src/launch_game.c	\
		src/grid_gestion.c	\
		src/prints.c		\
		src/ia_move.c

NAME 	=	matchstick

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W -Iinclude

LIB		=	-L lib -lib

all:	$(NAME)

make_lib:
	make -C lib all

$(NAME):	make_lib	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(LIB)

clean:
	make -C lib clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib fclean
	rm -f $(NAME)

re: 	fclean all