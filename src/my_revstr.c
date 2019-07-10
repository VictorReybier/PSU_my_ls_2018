/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverse a string
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_revstr(char *str)
{
    char buffer;
    int i = 0;

    for (; str[i] != '\0'; i++);
    for (int n = 0; n < i / 2; n++) {
        buffer = str[n];
        str[n] = str[i - 1 - n];
        str[i - 1 - n] = buffer;
    }
    return (str);
}