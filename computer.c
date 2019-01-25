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

int create_computer_matches(game_board_t *game_board, int computer_line)
{
    int random_matches;
    int lower = 1;
    int check;

    srand(time(NULL));
    random_matches = (rand() % (game_board->matches_max - lower + 1) + lower);
    check = find_matches_on_line(game_board->board[computer_line]);
    my_printf("CHECK = %i\n", check);
    if (random_matches > check)
        create_computer_matches(game_board, computer_line);
    else
        return (random_matches);
}

int create_computer_line(game_board_t *game_board)
{
    int random_line;
    int lower = 1;
    int check;

    random_line = (rand() % (game_board->lines - lower + 1) + lower);
    my_printf("IA LIGNE = %i\n", random_line);
    check = find_matches_on_line(game_board->board[random_line]);
    if (check == 0)
        create_computer_line(game_board);
    else
        return (random_line);
}

int computer_plays(game_board_t *game_board)
{
    int computer_line = create_computer_line(game_board);
    int computer_matches = create_computer_matches(game_board, computer_line);

    update_board(game_board, computer_line, computer_matches);
    my_printf("IA removes %i match(es) from line %i\n", computer_matches,
    computer_line);
    print_game_board(game_board->board);
    my_putchar('\n');
}
