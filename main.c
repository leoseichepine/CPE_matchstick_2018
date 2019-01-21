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

int find_matches_left(char **game_board)
{
    int res = 0;

    for (int y = 0; game_board[y] != NULL; y++) {
        for (int x = 0; game_board[y][x] != '\0'; x++) {
            if (game_board[y][x] == '|')
                res++;
        }
    }
    return (res);
}

game_board_t *create_game_board(int lines, int matches_max)
{
    game_board_t *game_board = malloc(sizeof(game_board_t));

    game_board->lines = lines;
    game_board->matches_max = matches_max;
    game_board->height = lines + 2;
    game_board->width = 2 * lines + 1;
    game_board->board = fill_board(lines);
    game_board->matches_left = find_matches_left(game_board->board);
    return (game_board);
}

int main(int ac, char *av[])
{
    game_board_t *game_board = create_game_board(my_atoi(av[1]), my_atoi(av[2]));

    if (error_handling(ac, av) == 84)
        return (84);
    print_game_board(game_board->board);
    loop_game(game_board);
    free_board(game_board->board);
    free(game_board);
    return (0);
}
