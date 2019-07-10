/*
** EPITECH PROJECT, 2019
** lflag_management.c
** File description:
** lflag
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

int size_file(char *filepath)
{
    struct stat sb;
    if (stat(filepath, &sb) != 0)
        return (0);
    display_size(sb.st_size);
    my_putchar(' ');
    my_putchar(' ');
}

int time_elapsed(char *filepath)
{
    struct stat sb;
    struct tm *time2;
    if (stat(filepath, &sb) != 0)
        return (0);
    char *buffer = ctime(&sb.st_mtime);
    char *str = manage_buffer(buffer);
    my_putstr(str);
    my_putchar(' ');
}

char *manage_buffer(char *buffer)
{
    int n = 0;
    char *str = malloc(sizeof(char) * 100);
    for (int i = 0; buffer[i + 4] != '\n'; i++) {
        if (buffer[i + 4] == ':')
            n++;
        if (n == 2)
            return (str);
        str[i] = buffer[i + 4];
    }
    return (str);
}

int user_permission(char *filepath)
{
    struct stat sb;
    if (stat(filepath, &sb) != 0)
        return (0);
    my_putstr((S_ISDIR(sb.st_mode)) ? "d" : "-");
    my_putstr((sb.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((sb.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((sb.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXOTH) ? "x" : "-");
    my_putchar('.');
    my_putchar(' ');
}

int user_name(char *filepath)
{
    struct group *grp;
    struct passwd *pws;
    uid_t uid = 1000;
    gid_t gid = 1000;
    pws = getpwuid(uid);
    my_putstr(pws->pw_name);
    my_putchar(' ');
    grp = getgrgid(gid);
    my_putstr(grp->gr_name);
    my_putchar(' ');
}