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

int find_last_match(char *line)
{
    int tmp = 0;
    int i = 0;

    for (i; line[i] != '\0'; i++) {
        if (line[i] == '|')
            tmp = 1;
        if (line[i] != '|' && tmp == 1)
            return (i - 1);
    }
    return (0);
}

int update_board(game_board_t *game_board, int line_number, int matches_number)
{
    int x = find_last_match(game_board->board[line_number]);

    for (int i = 0; i < matches_number; i++)
        game_board->board[line_number][x - i] = ' ';
    game_board->matches_left -= matches_number;
    return (0);
}
