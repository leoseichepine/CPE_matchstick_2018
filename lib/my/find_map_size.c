/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int find_rows(char const *filepath)
{
    int fd = open(filepath, O_RDWR);
    char *buffer = malloc(sizeof(char) * 10000);
    int i = 0;
    int res = 0;

    read(fd, buffer, 1000);
    while (buffer[i] != '\0') {
        i++;
        if (buffer[i] == '\n') {
            res++;
        }
    }
    close (fd);
    free (buffer);
    return (res);
}

int find_cols(char const *filepath)
{
    int fd = open(filepath, O_RDWR);
    char *buffer = malloc(sizeof(char) * 10000);
    int i = 0;

    read(fd, buffer, 10000);
    while (buffer[i] != '\n') {
        i++;
    }
    close(fd);
    free(buffer);
    return (i);
}
