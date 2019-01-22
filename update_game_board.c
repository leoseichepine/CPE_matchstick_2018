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

    for (int x = 0; line[x] != '\0'; x++) {
        if (line[x] == '|')
            tmp = 1;
        if (line[x + 1] != '|' && tmp == 1)
            return (x);
    }
}

int find_matches_left_on_line(char *line)
{
    int res = 0;

    for (int x = 0; line[x] != '\0'; x++)
        if (line[x] == '|')
            res++;
    return (res);
}

int update_board(game_board_t *game_board, int line_number, int matches_number)
{
    int x = find_last_match(game_board->board[line_number]);

    for (int i = 0; i < matches_number; i++)
        game_board->board[line_number][x - i] = ' ';
    my_printf("Player removes %i match(es) from line %i\n", matches_number, line_number);
    game_board->matches_left -= matches_number;
    return (0);
}
