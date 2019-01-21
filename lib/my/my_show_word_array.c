/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_show_word_array(char **tab, int height)
{
    for (int y = 0; y < height; y++) {
        my_putstr(tab[y]);
    }
    my_putchar('\n');
    return (0);
}
