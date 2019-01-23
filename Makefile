##
## EPITECH PROJECT, 2019
## CPE_matchstick_2018
## File description:
## __DESCRIPTION__
##

NAME	=	matchstick

SRC 	=	main.c\
			print_game_board.c\
			game_loop.c\
			update_game_board.c\
			game_board.c\
			error_handling_game_loop.c\
			player.c\
			computer.c

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
