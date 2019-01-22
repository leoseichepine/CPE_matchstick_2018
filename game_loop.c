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
        player_plays(game_board);
    }
    if (game_board->matches_left == 0) {
        my_printf("Player won, obviously\n");
        return (1);
    }
    return (0);
}
