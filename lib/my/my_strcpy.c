/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for(src[i]; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] == '\0';
    return (dest);
}
