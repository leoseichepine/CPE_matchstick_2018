/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** __DESCRIPTION__
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <unistd.h>
#include <stdio.h>

int error_handling(int ac, char *av[])
{
    if (ac < 3) {
        write(2, "Not enough arguments\n", 21);
        return (84);
    }
    if (ac > 3) {
        write(2, "Too many arguments\n", 19);
        return (84);
    }
}

void free_everything(game_board_t *game_board)
{
    free_board(game_board->board);
    free(game_board);
}

void init_game_board(game_board_t *game_board)
{
    print_game_board(game_board->board);
    my_putchar('\n');
}

int main(int ac, char *av[])
{
    game_board_t *game_board = malloc(sizeof(game_board_t));
    int err;

    if (error_handling(ac, av) == 84) {
        free(game_board);
        return (84);
    }
    if (create_game_board(my_atoi(av[1]), my_atoi(av[2]), game_board) == 84) {
        free(game_board);
        return (84);
    }
    init_game_board(game_board);
    if (loop_game(game_board) == 2) {
        free_everything(game_board);
        return (2);
    } else {
        free_everything(game_board);
        return (1);
    }
}
