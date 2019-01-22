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

int player_plays(game_board_t *game_board)
{
    int line_number = 0;
    int matches_number = 0;

    line_number = get_line_number(game_board);
    matches_number = get_matches_number(game_board, line_number);
    update_board(game_board, line_number,matches_number);
    print_game_board(game_board->board);
    return (0);
}

int get_line_number(game_board_t *game_board)
{
    char *tmp_line = NULL;
    size_t len = 0;
    int line_number = 0;

    my_printf("Line: ");
    getline(&tmp_line, &len, stdin);
    line_number = my_atoi(tmp_line);
    check_line_number(line_number, game_board);
    free(tmp_line);
    return (line_number);
}

int get_matches_number(game_board_t *game_board, int line_number)
{
    char *tmp_matches = NULL;
    size_t len = 0;
    int matches_number = 0;

    my_printf("Matches: ");
    getline(&tmp_matches, &len, stdin);
    matches_number = my_atoi(tmp_matches);
    check_matches_number(line_number, matches_number, game_board);
    free(tmp_matches);
    return (matches_number);
}
