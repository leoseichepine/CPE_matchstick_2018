/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <unistd.h>

typedef enum
{
    false,
    true,
}bool_t;

typedef struct s_game_board
{
    char **board;
    int lines;
    int height;
    int width;
    int matches_left;
    int matches_max;
}game_board_t;

int is_error_matches(game_board_t *game_board, int matches_number, int line_number);
int is_error_line(int line, game_board_t *game_board);
int computer_plays(game_board_t *game_board);
int player_plays(game_board_t *game_board);
int get_line_number(game_board_t *game_board);
int get_matches_number(game_board_t *game_board, int line_number);
int check_line_number(int line_number, game_board_t *game_board);
int check_matches_number(int line_number, int matches_number,
    game_board_t *game_board);
int find_last_match(char *line);
int find_matches_on_line(char *line);
int find_matches_left(char **game_board);
game_board_t *create_game_board(int lines, int matches_max);
int loop_game(game_board_t *game_board);
int update_board(game_board_t *game_board, int line_number, int matches_number);
int free_board(char **game_board);
char **load_board(int height, int width);
char **fill_board(int lines);
void print_game_board(char **game_board);

#endif //MATCHSTICK_H_
