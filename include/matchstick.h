/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** __DESCRIPTION__
*/

#include <unistd.h>

typedef struct s_game_board
{
    char **board;
    int lines;
    int height;
    int width;
    int matches_left;
    int matches_max;
}game_board_t;

void loop_game(game_board_t *game_board);
int update_board(game_board_t *game_board, int line_number, int matches_number);
int free_board(char **game_board);
char **load_board(int height, int width);
char **fill_board(int lines);
void print_game_board(char **game_board);
