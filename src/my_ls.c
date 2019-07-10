/*
** EPITECH PROJECT, 2019
** my_ls.c
** File description:
** recode my_ls
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

static int size_tot = 0;

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] != '-')
        ls_no_flag_filepath(av[1]);
    if (ac == 1)
        ls_no_flag(av[1]);
    if (ac == 3 && av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0')
        total_nbr(av[2]);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0') {
        max_size_no_filepath();
        l_flag_no_filepath();
    }
    if (ac == 3 && av[1][0] == '-' && av[1][1] == 'a' && av[1][2] == '\0')
        a_flag(av[2]);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'a' && av[1][2] == '\0') {
        max_size(".");
        a_flag_no_filepath();
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'R' && av[1][2] == '\0') {
        ls_no_flag_r(av[1]);
        rflag();
    }
}

int hard_link(char *filepath)
{
    struct stat sb;
    if (stat(filepath, &sb) != 0)
        return (0);
    my_put_nbr(sb.st_nlink);
    my_putchar(' ');
}

int hidden_file(char *filepath)
{
    if (filepath[0] == '.')
        return (0);
}

int l_flag(char *filepath)
{
    printf("azerty\n");
    DIR *dir2;
    struct dirent *dir;
    struct stat sb;
    dir2 = opendir(filepath);
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
