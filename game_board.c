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

int error_args(int lines, int matches_max)
{
    if (matches_max <= 0) {
        my_printf("Matches number must be positive\n");
        return (84);
    }
    if (lines == 1 && matches_max >= lines)
        return (84);
    if (lines > 99 || lines < 1) {
        my_printf("Line number must be between 0 and 100\n");
        return (84);
    }
    return (0);
}

int create_game_board(int lines, int matches_max, game_board_t *game_board)
{
    if (error_args(lines, matches_max) == 84)
        return (84);
    game_board->lines = lines;
    game_board->matches_max = matches_max;
    game_board->height = lines + 2;
    game_board->width = 2 * lines + 1;
    game_board->board = fill_board(lines);
    if (game_board->board == NULL)
        return (84);
    game_board->matches_left = find_matches_left(game_board->board);
    return (0);
}
