/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i,j;

    i = j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
