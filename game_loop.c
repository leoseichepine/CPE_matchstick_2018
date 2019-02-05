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

int end_condition_player(game_board_t *game_board)
{
    if (game_board->matches_left == 0) {
        my_printf("You lost, too bad...\n");
        return(2);
    }
    return (0);
}

int end_condition_ai(game_board_t *game_board)
{
    if (game_board->matches_left == 0) {
        my_printf("I lost... snif... but I'll get you next time !\n");
        return (1);
    }
    return (0);
}

int loop_game(game_board_t *game_board)
{
    int err;

    while (game_board->matches_left > 0) {
        my_printf("Your turn:\n");
        err = player_plays(game_board);
        if (err == 111)
            return (0);
        if (end_condition_player(game_board) == 2)
            return (2);
        my_printf("AI's turn...\n");
        err = computer_plays(game_board);
        if (err == 111)
            return (0);
        if (end_condition_ai(game_board) == 1)
            return (1);
    }
    return (0);
}
