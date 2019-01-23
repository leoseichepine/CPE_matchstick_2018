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
        if (player_plays(game_board) == 110)
            return (0);
        if (game_board->matches_left == 1) {
            my_printf("Player won, GG\n");
            return (1);
        }
        if (game_board->matches_left == 0) {
            my_printf("IA won, you suck, it plays randomly\n");
            return (2);
        }
        my_printf("AI's turn...\n");
        computer_plays(game_board);
    }
    return (0);
}
