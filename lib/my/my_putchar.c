/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
