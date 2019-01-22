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

void check_line_number(int line_number, game_board_t *game_board)
{
    if (line_number <= 0 || line_number > game_board->lines) {
        write(1, "Error: This line is out of range\n", 33);
        loop_game(game_board);
    } else
        return;
}

void check_matches_number(int line_number, int matches_number, game_board_t *game_board)
{
    int m_line = find_matches_left_on_line(game_board->board[line_number]);

    if (matches_number <= 0) {
        write(1, "Error: You have to remove at least one match\n", 45);
        loop_game(game_board);
    }
    else if (matches_number > game_board->matches_max) {
        my_printf("You cannot removes more than %i matches per turn\n", game_board->matches_max);
        loop_game(game_board);
    }
    else if (matches_number > m_line) {
        write(1, "Error: Not enough matches on this line\n", 39);
        loop_game(game_board);
    }
    return;
}
