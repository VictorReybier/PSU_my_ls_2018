/*
** EPITECH PROJECT, 2019
** rflag_management.c
** File description:
** r flag
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

int disp_under_dir(char *filepath)
{
    DIR *dir2;
    struct dirent *dir;
    dir2 = opendir(filepath);
    while ((dir = readdir(dir2)) != NULL) {
        if (hidden_file(dir->d_name) == 0);
        else {
            under_dir(dir->d_name);
            my_putstr(dir->d_name);
            my_putchar(32);
            my_putchar(32);
        }
    }
}

int under_dir(char *filepath)
{
    struct stat sb;
    if (stat(filepath, &sb) != 0)
        return (0);
    if (S_ISDIR(sb.st_mode)) {
        my_putchar('.');
        my_putchar('/');
        my_putstr(filepath);
        my_putchar(':');
        my_putchar(10);
        disp_under_dir(filepath);
    }
}

int ls_no_flag_r(char *filepath)
{
    DIR *dir2;
    struct dirent *dir;
    dir2 = opendir(".");
    my_putchar('.');
    my_putchar(':');
    my_putchar(10);
    while ((dir = readdir(dir2)) != NULL) {
        if (hidden_file(dir->d_name) == 0);
        else {
            my_putstr(dir->d_name);
            my_putchar(32);
            my_putchar(32);
        }
    }
    my_putchar(10);
    my_putchar(10);
}

int rflag(void)
{
    DIR *dir2;
    struct dirent *dir;
    dir2 = opendir(".");
    while ((dir = readdir(dir2)) != NULL) {
        if (hidden_file(dir->d_name) == 0);
        else
            under_dir(dir->d_name);
    }
    my_putchar(10);
}