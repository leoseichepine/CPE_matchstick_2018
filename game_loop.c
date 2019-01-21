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


void display_error(int err)
{
    switch (err) {
        default:
            return;
    }
}

void loop_game(game_board_t *game_board)
{
    char *tmp = NULL;
    size_t len = 0;
    int line_number = 0;
    int matches_number = 0;
    int err = 0;

    while (game_board->matches_left > 0) {
        my_printf("Line: ");
        getline(&tmp, &len, stdin);
        line_number = my_atoi(tmp);
        my_printf("Matches: ");
        getline(&tmp, &len, stdin);
        matches_number = my_atoi(tmp);
        if (err = update_board(game_board, line_number, matches_number) != 0) {
            display_error(err);
        } else
            print_game_board(game_board->board);
    }
    free(tmp);
}
