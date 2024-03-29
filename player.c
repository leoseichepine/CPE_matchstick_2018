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

bool_t is_str_num(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9' && str[i] != '-')
            return (false);
    }
    return (true);
}

int get_matches_number(game_board_t *game_board, int line_number)
{
    char *tmp_matches = NULL;
    size_t len = 0;
    int matches_number;
    int err;

    my_printf("Matches: ");
    err = getline(&tmp_matches, &len, stdin);
    if (err == -1) {
        my_putchar('\n');
        return (111);
    }
    if (!is_str_num(tmp_matches)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (84);
    }
    matches_number = my_atoi(tmp_matches);
    if (is_error_matches(game_board, matches_number, line_number) == 84)
        return (84);
    free(tmp_matches);
    return (matches_number);
}

int get_line_number(game_board_t *game_board)
{
    char *tmp_line = NULL;
    size_t len = 0;
    int line_number;
    int err;

    my_printf("Line: ");
    err = getline(&tmp_line, &len, stdin);
    if (err == -1) {
        my_putchar('\n');
        return (111);
    }
    if (!is_str_num(tmp_line)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (84);
    }
    line_number = my_atoi(tmp_line);
    if (is_error_line(line_number, game_board) == 84)
        return (84);
    free(tmp_line);
    return (line_number);
}

void end_player_turn(game_board_t *game_board, int line_number,
                    int matches_number)
{
    update_board(game_board, line_number, matches_number);
    my_printf("Player removed %i match(es) from line %i\n",
    matches_number, line_number);
    print_game_board(game_board->board);
    if (game_board->matches_left > 0)
        my_putchar('\n');
}

int player_plays(game_board_t *game_board)
{
    int line_number = get_line_number(game_board);
    int matches_number;

    if (line_number == 111)
        return (111);
    while (line_number == 84) {
        line_number = get_line_number(game_board);
        if (line_number == 111)
            return (111);
    }
    matches_number = get_matches_number(game_board, line_number);
    if (matches_number == 111)
        return (111);
    if (matches_number == 84) {
        return (player_plays(game_board));
        if (matches_number == 111)
            return (111);
    }
    end_player_turn(game_board, line_number, matches_number);
    return (0);
}
