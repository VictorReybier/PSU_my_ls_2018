/*
** EPITECH PROJECT, 2019
** display_management.c
** File description:
** display -l
*/

#include <stdarg.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "../include/my.h"
#include <stdio.h>
#include <grp.h>

static int max_nbr = 0;

char *int_to_string(int nb)
{
    int pow = 1;
    int nbcpy = nb;
    char *buffer = malloc(sizeof(char) * 4);
    int i = 0;
    while (nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
    }
    while (nb > 9) {
        buffer[i] = nb / pow + 48;
        nb = nb % pow;
        pow = pow / 10;
        i++;
    }
    buffer[i] = nb + 48;
    buffer[i + 1] = '\0';
    return (buffer);
}

int max_size(char *filepath)
{
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(filepath);
    while ((dir = readdir(dir2)) != NULL) {
        int nbr = get_file_size(dir->d_name);
        max_size2(dir->d_name, nbr);
    }
    closedir(dir2);
    l_flag(filepath);
}

int get_file_size(char *filepath)
{
    struct stat sb;
    if (stat(filepath, &sb) != 0)
        return (0);
    int nbr = sb.st_size;
    return (nbr);
}

int max_size2(char *filepath, int nb)
{
    char *buffer = int_to_string(nb);
    static int first_call = 0;
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(".");
    int nbr = 0;
    while ((dir = readdir(dir2)) != NULL) {
        nbr = my_strlen(buffer);
        if (nbr > max_nbr)
            max_nbr = nbr;
    }
}

int display_size(int nb)
{
    char *buffer = int_to_string(nb);
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(".");
    int nbr = 0;
    nbr = my_strlen(buffer);
    char *rev_buffer = my_revstr(buffer);
    int nbr2 = max_nbr - nbr;
    for (int i = 0; i < nbr2; i++) {
        rev_buffer[nbr] = ' ';
        nbr++;
    }
    char *re_rev_buffer = my_revstr(rev_buffer);
    my_putstr(re_rev_buffer);
}