/*
** EPITECH PROJECT, 2019
** CPE_matchstick_bootstrap_2018
** File description:
** __DESCRIPTION__
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <unistd.h>

int free_board(char **game_board)
{
    for (int i = 0; game_board[i] != NULL; i++)
        free(game_board[i]);
    free(game_board);
    return (0);
}

char **load_board(int height, int width)
{
    char **game_board = (malloc(sizeof(char *) * (height + 1)));

    for (int i = 0; i < height; i++) {
        game_board[i] = malloc(sizeof(char) * (width + 1));
        game_board[i][width] = '\0';
    }
    game_board[height] = NULL;
    return (game_board);
}

char **fill_board(int lines)
{
    int height = lines + 2; // 6
    int width = 2 * lines + 1; // 9
    int demilen = width / 2;
    int off = 0;
    char **game_board = load_board(height, width);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            game_board[y][x] = ' ';
            if (y == 0 || y == height - 1)
                game_board[y][x] = '*';
            else if (x == 0 || x == width - 1)
                game_board[y][x] = '*';
        }
    }
    for (int y = 1; y < height - 1; y++) {
        for (int x = 0; x < width; x++)
            if (x <= demilen + off && x >= demilen - off)
                game_board[y][x] = '|';
        off++;
    }
    return (game_board);
}

void print_game_board(char **game_board)
{
    for (int i = 0; game_board[i] != NULL; i++) {
        my_putstr(game_board[i]);
        my_putchar('\n');
    }
}
