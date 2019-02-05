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

int is_error_matches(game_board_t *game_board, int matches_number,
                    int line_number)
{
    int on_line = find_matches_on_line(game_board->board[line_number]);

    if (matches_number <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (84);
    }
    if (matches_number > on_line) {
        my_printf("Error: not enough matches on this line\n");
        return (84);
    }
    if (matches_number > game_board->matches_max) {
        my_printf("Error: you cannot remove more than %i matches per turn\n",
        game_board->matches_max);
        return (84);
    }
}

int is_error_line(int line, game_board_t *game_board)
{
    if (line <= 0 || line > game_board->lines) {
        my_printf("Error: This line is out of range\n");
        return (84);
    }
    return (0);
}
