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

int check_line_number(int line_number, game_board_t *game_board)
{
    if (line_number <= 0 || line_number > game_board->lines) {
        write(1, "Error: This line is out of range\n", 33);
        return (84);
    } else
        return (0);
}

int check_matches_number(int matches_on_line, int matches_number,
                        game_board_t *game_board)
{
    if (matches_number <= 0) {
        write(1, "Error: You have to remove at least one match\n", 45);
        return (84);
    }
    else if (matches_number > game_board->matches_max) {
        my_printf("You cannot removes more than %i matches per turn\n",
        game_board->matches_max);
        return (84);
    }
    else if (matches_number > matches_on_line) {
        write(1, "Error: Not enough matches on this line\n", 39);
        return (84);
    }
    return (0);
}
