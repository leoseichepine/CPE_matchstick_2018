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

int loop_game(game_board_t *game_board)
{
    while (game_board->matches_left > 0) {
        my_printf("Your turn:\n");
        if (player_plays(game_board) == 110) {
            my_putchar('\n');
            return (0);
        }
        if (game_board->matches_left == 0) {
            my_printf("You lost, too bad...\n");
            return (2);
        }
        my_printf("AI's turn...\n");
        computer_plays(game_board);
        if (game_board->matches_left == 0) {
            my_printf("I lost... snif... but I'll get you next time !\n");
            return (1);
        }
    }
    return (0);
}
