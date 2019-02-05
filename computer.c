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
#include <time.h>

int find_matches_on_line(char *line)
{
    int res = 0;

    for (int x = 0; line[x] != '\0'; x++)
        if (line[x] == '|')
            res++;
    return (res);
}

int create_computer_matches(game_board_t *game_board, int computer_line)
{
    int random_matches = 1;

    return (random_matches);
}

int create_computer_line(game_board_t *game_board)
{
    int random_line;

    random_line = (rand() % game_board->lines + 1);
    return (random_line);
}

int computer_plays(game_board_t *game_board)
{
    int computer_line;
    int computer_matches = 1;

    computer_line = create_computer_line(game_board);
    while (find_matches_on_line(game_board->board[computer_line]) == 0)
        computer_line = create_computer_line(game_board);
    computer_matches = create_computer_matches(game_board, computer_line);
    while (computer_matches >
        find_matches_on_line(game_board->board[computer_line]))
        computer_matches = create_computer_matches(game_board, computer_line);
    update_board(game_board, computer_line, computer_matches);
    my_printf("AI removed %i match(es) from line %i\n", computer_matches,
    computer_line);
    print_game_board(game_board->board);
    if (game_board->matches_left > 1)
        my_putchar('\n');
}
