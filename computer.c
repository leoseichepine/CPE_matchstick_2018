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
    int random_matches;
    int lower = 1;

    srand(time(0));
    random_matches = (rand() % (game_board->matches_max - lower + 1) + lower);
    return (random_matches);
}

int create_computer_line(game_board_t *game_board)
{
    int random_line;
    int lower = 1;

    random_line = (rand() % (game_board->lines - lower + 1) + lower);
    // my_printf("AI line = %i\n", random_line);
    return (random_line);
}

int computer_plays(game_board_t *game_board)
{
    int computer_line;
    int computer_matches = 1;

    computer_line = create_computer_line(game_board);
    while (find_matches_on_line(game_board->board[computer_line]) == 0)
        computer_line = create_computer_line(game_board);
    update_board(game_board, computer_line, computer_matches);
    my_printf("AI removes %i match(es) from line %i\n", computer_matches,
    computer_line);
    print_game_board(game_board->board);
    my_putchar('\n');
}
