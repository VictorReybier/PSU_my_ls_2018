/*
** EPITECH PROJECT, 2019
** aflag_management.c
** File description:
** aflag
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

int a_flag(char *filepath)
{
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(".");
    while ((dir = readdir(dir2)) != NULL) {
        user_permission(dir->d_name);
        hard_link(dir->d_name);
        user_name(dir->d_name);
        size_file(dir->d_name);
        time_elapsed(dir->d_name);
        my_putstr(dir->d_name);
        my_putchar(10);
        }
    closedir(dir2);
}

int a_flag_no_filepath(void)
{
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(".");
    while ((dir = readdir(dir2)) != NULL) {
        user_permission(dir->d_name);
        hard_link(dir->d_name);
        user_name(dir->d_name);
        size_file(dir->d_name);
        time_elapsed(dir->d_name);
        my_putstr(dir->d_name);
        my_putchar(10);
        }
    closedir(dir2);
}