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

    if (!game_board)
        return (NULL);
    for (int i = 0; i < height; i++) {
        game_board[i] = malloc(sizeof(char) * (width + 1));
        game_board[i][width] = '\0';
    }
    game_board[height] = NULL;
    return (game_board);
}

void print_matches(int lines, char **game_board)
{
    int height = lines + 2;
    int width = 2 * lines + 1;
    int demilen = width / 2;
    int off = 0;

    for (int y = 1; y < height - 1; y++) {
        for (int x = 0; x < width; x++)
            if (x <= demilen + off && x >= demilen - off)
                game_board[y][x] = '|';
        off++;
    }
}

char **fill_board(int lines)
{
    int height = lines + 2;
    int width = 2 * lines + 1;
    char **game_board = load_board(height, width);

    if (game_board == NULL)
        return (NULL);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            game_board[y][x] = ' ';
            if (y == 0 || y == height - 1)
                game_board[y][x] = '*';
            else if (x == 0 || x == width - 1)
                game_board[y][x] = '*';
        }
    }
    print_matches(lines, game_board);
    return (game_board);
}

void print_game_board(char **game_board)
{
    for (int i = 0; game_board[i] != NULL; i++) {
        my_putstr(game_board[i]);
        my_putchar('\n');
    }
}
