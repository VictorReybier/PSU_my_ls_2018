/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** Counts and returns the number of characters
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i = i + 1;
    }

    return (i);
    my_putchar(10);
    return (0);
}
