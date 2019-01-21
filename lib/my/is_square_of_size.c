/*
** EPITECH PROJECT, 2018
** is_square_of_size
** File description:
**
*/

#include <stdlib.h>
#include "my.h"

void modify_map(char **map, int x, int y, int square_size)
{
    int i = x;
    int j = y;

    while (i <= x + square_size - 1) {
        while (j <= y + square_size - 1) {
            map[i][j] = 'X';
            j++;
        }
        j = y;
        i++;
    }
}

int is_square_of_size(char **buffer, int x, int y, int square_size)
{
    int i = x;
    int j = y;

    if (buffer[x][y] == 'o')
        return (0);
    while (i < x + square_size) {
        while (j < y + square_size) {
            if (buffer[i][j] == '.')
                j++;
            else if (buffer[i][j] == 'o')
                return (0);
        }
        j = y;
        i++;
    }
    return (1);
}
