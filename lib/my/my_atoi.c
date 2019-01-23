/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_atoi(char *str)
{
    int newnb = 0;
    int sign = 0;
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == '-')
            sign++;
        i++;
    }
    while (*str != '\0' && *str != '\n') {
        if (*str >= '0' && *str <= '9')
            newnb = newnb * 10 + (*str - '0');
        str++;
    }
    if (sign % 2 != 0)
        newnb = newnb * (-1);
    return (newnb);
}
