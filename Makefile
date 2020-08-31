# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 17:46:57 by sid-bell          #+#    #+#              #
#    Updated: 2020/08/31 23:40:35 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=malloc

INC=src/

OBJ =	src/ft_show_alloc_mem.o src/ft_realloc.o\
		src/ft_zone.o src/ft_list.o src/ft_malloc.o\
		src/ft_meduim.o src/ft_getzone.o src/ft_large.o\
		src/ft_small.o src/ft_free.o src/ft_memcpy.o\
		main.o

CFLAGS= -g -I$(INC) -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJ)
	#ar -rc libmalloc.a $(OBJ)
	gcc -g $(OBJ) -o malloc
clean:
	rm -rf $(OBJ)

re:clean all

fclean:clean
	rm -rf $(NAME)