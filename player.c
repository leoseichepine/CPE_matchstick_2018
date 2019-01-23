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

int find_matches_on_line(char *line)
{
    int res = 0;

    for (int x = 0; line[x] != '\0'; x++)
        if (line[x] == '|')
            res++;
    return (res);
}

int get_matches_number(void)
{
    char *tmp_matches = NULL;
    size_t len = 0;
    int matches_number = 0;

    my_printf("Matches: ");
    getline(&tmp_matches, &len, stdin);
    matches_number = my_atoi(tmp_matches);
    free(tmp_matches);
    return (matches_number);
}

int get_line_number(void)
{
    char *tmp_line = NULL;
    size_t len = 0;
    int line_number = 0;

    my_printf("Line: ");
    getline(&tmp_line, &len, stdin);
    line_number = my_atoi(tmp_line);
    free(tmp_line);
    return (line_number);
}

int player_plays(game_board_t *game_board)
{
    int line_number;
    int matches_number;
    int matches_on_line;
    int err;

    line_number = get_line_number();
    while (check_line_number(line_number, game_board) == 84)
        line_number = get_line_number();
    matches_on_line = find_matches_on_line(game_board->board[line_number]);
    matches_number = get_matches_number();
    err = check_matches_number(matches_on_line, matches_number, game_board);
    if (err == 84)
        player_plays(game_board);
    else {
        update_board(game_board, line_number, matches_number);
        my_printf("Player removes %i match(es) from line %i\n\n",
        matches_number, line_number);
        print_game_board(game_board->board);
    }
    return (0);
}
