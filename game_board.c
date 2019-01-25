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

game_board_t *create_game_board(int lines, int matches_max)
{
    game_board_t *game_board = malloc(sizeof(game_board_t));

    if (!game_board || lines > 100)
        return (NULL);
    game_board->lines = lines;
    game_board->matches_max = matches_max;
    game_board->height = lines + 2;
    game_board->width = 2 * lines + 1;
    game_board->board = fill_board(lines);
    if (game_board->board == NULL)
        return (NULL);
    game_board->matches_left = find_matches_left(game_board->board);
    return (game_board);
}
