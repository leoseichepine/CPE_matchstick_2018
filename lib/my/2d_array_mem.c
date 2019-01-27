/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int free_2d_array(char **buffer, int rows)
{
    int i = 0;

    for (i; i < rows + 1; i++)
        free(buffer[i]);
    free(buffer);
    return (0);
}

// int find_biggest_square(char **map, int rows, int cols, int x, int y)
// {
//     int res;
//
//     for (int square_size = cols - 1; square_size > 0; square_size--) {
//         for (x; x < rows - square_size; x++) {
//             for (y; y < cols - square_size; y++) {
//                 res = is_square_of_size(map, x, y, square_size);
//                 if (res == 1) {
//                     modify_map(map, x, y, square_size);
//                     break;
//                 }
//             }
//             y = 0;
//             if (res == 1)
//                 break;
//         }
//         x = 0;
//         y = 0;
//         if (res == 1)
//             break;
//     }
//     return (0);
// }

int skip_first_line(char const *str)
{
    int k;

    while (str[k] != '\n')
        k++;
    k++;
    return (k);
}

char **mem_alloc_2d_array(char const *str, int rows, int cols)
{
    int i = 0;
    char **buffer = malloc(sizeof(char) * rows * (cols + 1));
    int j = 0;
    int k = 0;

    buffer[i] = malloc(sizeof(char) * cols + 1);
    for (k; str[k] != '\0'; k++) {
        if (str[k] == '\n') {
            buffer[i][j] = '\n';
            j = 0;
            i++;
            buffer[i] = malloc(sizeof(char) * cols + 1);
            k++;
        }
        buffer[i][j] = str[k];
        j++;
    }
    return (buffer);
}
