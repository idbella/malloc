# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 17:46:57 by sid-bell          #+#    #+#              #
#    Updated: 2019/11/08 19:49:58 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=malloc

INC=src/

OBJ= src/ft_zone.o src/ft_list.o src/ft_malloc.o src/ft_meduim.o src/ft_getzone.o src/ft_large.o src/ft_small.o src/ft_free.o main.o

CFLAGS= -g -I$(INC) -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJ)
	gcc -g $(OBJ) -o malloc
clean:
	rm -rf $(OBJ)
