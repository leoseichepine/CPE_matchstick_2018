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

int get_matches_number(void)
{
    char *tmp_matches = NULL;
    size_t len = 0;
    int matches_number = 0;

    my_printf("Matches: ");
    if (getline(&tmp_matches, &len, stdin) == -1)
        return (110);
    else if (is_str_num(tmp_matches) == false) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (111);
    } else {
        matches_number = my_atoi(tmp_matches);
        free(tmp_matches);
        return (matches_number);
    }
}

int get_line_number(game_board_t *game_board)
{
    char *tmp_line = NULL;
    size_t len = 0;
    int line_number = 0;

    my_printf("Line: ");
    if (getline(&tmp_line, &len, stdin) == - 1)
        return (110);
    else if (is_str_num(tmp_line) == false) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (111);
    } else {
        line_number = my_atoi(tmp_line);
        free(tmp_line);
        return (line_number);
    }
}

void end_player_turn(game_board_t *game_board, int line_number,
                    int matches_number)
{
    update_board(game_board, line_number, matches_number);
    my_printf("Player removes %i match(es) from line %i\n",
    matches_number, line_number);
    print_game_board(game_board->board);
    if (game_board->matches_left > 0)
        my_putchar('\n');
}

int player_plays(game_board_t *game_board)
{
    int line_number = get_line_number(game_board);
    int matches_number;
    int matches_on_line;
    int err;

    if (line_number == 110)
        return (110);
    while (line_number == 111 || check_line_number(line_number, game_board) != 0)
        line_number = get_line_number(game_board);
    matches_on_line = find_matches_on_line(game_board->board[line_number]);
    matches_number = get_matches_number();
    if (matches_number == 110)
        return (110);
    err = check_matches_number(matches_on_line, matches_number, game_board);
    if (err == 84)
        player_plays(game_board);
    else
        end_player_turn(game_board, line_number, matches_number);
    return (0);
}
