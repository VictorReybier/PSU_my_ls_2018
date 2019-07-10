/*
** EPITECH PROJECT, 2019
** total_management.c
** File description:
** manage the total number
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

static int size_tot;

int total_nbr(char *filepath)
{
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(filepath);
    while ((dir = readdir(dir2)) != NULL) {
        if (hidden_file(dir->d_name) == 0);
        else
            total_size(dir->d_name);
    }
    my_putstr("total ");
    my_put_nbr(size_tot);
    my_putchar(10);
    max_size(filepath);
}

int total_size(char *filepath)
{
    struct stat sb;
    if (stat(filepath, &sb) != 0)
        return (0);
    size_tot = size_tot + sb.st_blocks / 2;
    return (0);
}