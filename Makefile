##
## EPITECH PROJECT, 2018
## Makefile_compil
## File description:
## Makefile compilation programme
##

NAME	=	print_game_board

SRC 	=	print_game_board.c\

RM		=	rm -f

OBJ 	=	$(SRC:.c=.o)

CC		=	gcc

LIB 	= 	-Llib/my -lmy

all 	:	$(NAME) clean

clean	:
			$(RM) *.o
			$(RM) *.gcno *.gcda *~ *#

$(NAME)	:	$(OBJ)
			$(CC) -g -o $(NAME) $(OBJ) $(LIB)

fclean	:
			$(RM) *.o
			$(RM) *.gcno *.gcda *~ *#
			$(RM) $(NAME)

re		:	fclean all
