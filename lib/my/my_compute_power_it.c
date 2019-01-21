/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_compute_power_it(int nb, int p)
{
    int i;
    long res;

    i = 0;
    res = 1;
    if(p == 0)
        return (1);
    if(p < 0)
        return (0);
    if(p == 1)
        return (nb);
    while (i < p) {
        res *= nb;
        i++;
    }
    return (res);
}
