/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;
    int i = 0;

    while (str[i] != '\0') {
        len++;
        i++;
    }
    return (len);
}
