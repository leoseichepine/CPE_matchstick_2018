/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/


#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef int(*fctptr_t)(va_list arg);

int find_int_len(int nb);
int itab_to_i(int arr[], int len);
void modify_map(char **buffer, int x, int y, int square_size);
int skip_first_line(char const *str);
int int_len_finder(int nb);
int print_tab(char **buffer);
int find_biggest_square(char **map, int rows, int cols, int x, int y);
int is_square_of_size(char **buffer, int x, int y, int square_size);
int my_show_word_array(char **tab, int height);
int free_2d_array(char **buffer, int rows);
char **mem_alloc_2d_array(char const *str, int rows, int cols);
int find_rows(char const *filepath);
int find_cols(char const *filepath);
int print_int(va_list arg);
int print_deci(va_list arg);
int print_unsigned_int(va_list arg);
int print_pct(va_list arg);
int print_ptr(va_list arg);
int print_char(va_list arg);
int print_str(va_list arg);
int print_str_oct(va_list arg);
int print_octal(va_list arg);
int print_hexa_uc(va_list arg);
int print_hexa_lc(va_list arg);
int print_binary(va_list arg);
int my_put_unsigned_int(unsigned int nb);
int switch_format(char const *format, va_list arg);
int my_printf(char const *format, ...);
int my_putstr_oct(char *str);
char *my_itoa(int nb);
int my_atoi(char *str);
int convert_dec_to_hexa_uc(unsigned long nb);
int convert_dec_to_hexa_lc(unsigned long nb);
int convert_base(int nb, int base);
int my_putchar(char);
int my_compute_power_rec(int nb, int p);
int my_putnbr(int nbr);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
void my_swap(int *a, int *b);

#endif //MY_H
