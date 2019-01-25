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

int main(int ac, char *av[])
{
    game_board_t *game_board;

    if (error_handling(ac, av) == 84)
        return (84);
    game_board = create_game_board(my_atoi(av[1]),
    my_atoi(av[2]));
    if (game_board == NULL)
        return (84);
    print_game_board(game_board->board);
    my_putchar('\n');
    loop_game(game_board);
    free_board(game_board->board);
    free(game_board);
    return (0);
}
