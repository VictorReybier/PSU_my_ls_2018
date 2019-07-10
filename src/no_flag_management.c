/*
** EPITECH PROJECT, 2019
** no_flag_management.c
** File description:
** no flag management
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

int max_size_no_filepath(void)
{
    printf("azerty\n");
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(".");
    while ((dir = readdir(dir2)) != NULL) {
        int nbr = get_file_size(dir->d_name);
        max_size2(dir->d_name, nbr);
    }
    closedir(dir2);
    l_flag_no_filepath();
}

int ls_no_flag_filepath(char *filepath)
{
    DIR *dir2;
    struct dirent *dir;
    dir2 = opendir(filepath);
    while ((dir = readdir(dir2)) != NULL) {
        if (hidden_file(dir->d_name) == 0);
        else {
            my_putstr(dir->d_name);
            my_putchar(32);
            my_putchar(32);
        }
    }
    my_putchar(10);
    closedir(dir2);
}

int ls_no_flag(char *filepath)
{
    DIR *dir2;
    struct dirent *dir;
    dir2 = opendir(".");
    while ((dir = readdir(dir2)) != NULL) {
        if (hidden_file(dir->d_name) == 0);
        else {
            my_putstr(dir->d_name);
            my_putchar(32);
            my_putchar(32);
        }
    }
    my_putchar(10);
    closedir(dir2);
}

int l_flag_no_filepath(void)
{
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(".");
    while ((dir = readdir(dir2)) != NULL) {
        if (hidden_file(dir->d_name) == 0);
        else {
        user_permission(dir->d_name);
        hard_link(dir->d_name);
        user_name(dir->d_name);
        size_file(dir->d_name);
        time_elapsed(dir->d_name);
        my_putstr(dir->d_name);
        my_putchar(10);
        }
    }
    closedir(dir2);
}