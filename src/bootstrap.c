
** EPITECH PROJECT, 2019
** bootstrap.c
** File description:
** first ls steps
*/
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int file_name(char *str)
{
    my_putstr("Name : ");
    my_putstr(str);
    my_putchar(10);
}

int inode_number(char *filepath)
{
    struct stat sb;
    if(stat(filepath, &sb) != 0)
        return(0);
    my_putstr("Inode : ");
    my_put_nbr(sb.st_ino);
    my_putchar(10);
}

int hard_link(char *filepath)
{
    struct stat sb;
    if(stat(filepath, &sb) != 0)
        return (0);
    my_putstr("Hard Link : ");
    my_put_nbr(sb.st_nlink);
    my_putchar(10);
}

int size_file(char *filepath)
{
    struct stat sb;
    if(stat(filepath, &sb) != 0)
        return (0);
    my_putstr("Size : ");
    my_put_nbr(sb.st_size);
    my_putchar(10);
}

int allocated_space(char *filepath)
{
    struct stat sb;
    if(stat(filepath, &sb) != 0)
        return (0);
    my_putstr("Allocated Space : ");
    my_put_nbr(sb.st_blocks);
    my_putchar(10);
}

int uid_file(char *filepath)
{
    struct stat sb;
    if(stat(filepath, &sb) != 0)
        return (0);
    my_putstr("UID : ");
    my_put_nbr(sb.st_uid);
    my_putchar(10);
}

int gid_file(char *filepath)
{
    struct stat sb;
    if(stat(filepath, &sb) != 0)
        return (0);
    my_putstr("GID : ");
    my_put_nbr(sb.st_gid);
    my_putchar(10);
}

int main(int ac, char **av)
{
    file_name(av[1]);
    inode_number(av[1]);
    hard_link(av[1]);
    size_file(av[1]);
    allocated_space(av[1]);
    uid_file(av[1]);
    gid_file(av[1]);
}
