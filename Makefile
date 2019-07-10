##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME =	my_ls

OBJ	=	$(SRC:.c=.o)

SRC	=	src/my_ls.c	\
		src/my_put_nbr.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		include/my.h	\
		src/lflag_management.c	\
		src/aflag_management.c	\
		src/display_management.c	\
		src/my_strlen.c	\
		src/no_flag_management.c	\
		src/my_revstr.c	\
		src/total_management.c	\
		src/rflag_management.c	\

all:
		gcc -o $(NAME) $(SRC) -lm
		ar rc libmy.a $(SRC)

clean:
		rm -f *.o

fclean:	clean
		rm -rf $(NAME)

re:		fclean all