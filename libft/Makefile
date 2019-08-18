# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 16:23:12 by sid-bell          #+#    #+#              #
#    Updated: 2019/05/08 01:53:36 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFILES=ft_atoi.c ft_bzero.c ft_csd.c ft_errors_list.c ft_isalnum.c\
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c\
ft_itoa.c ft_lstadd.c ft_lstcount.c ft_lstdel.c ft_lstdelone.c\
ft_lstfold.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstprint.c\
ft_lstrev.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_nbrlen.c\
ft_printf.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcount.c ft_strcpy.c ft_strctrim.c\
ft_strdel.c ft_strdup.c ft_strequ.c ft_strerror.c ft_striter.c ft_striteri.c\
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c\
ft_strnew.c ft_strnstr.c ft_strpos.c ft_strrchr.c ft_strrepeat.c\
ft_strreplace.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c\
ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c
OFILES=ft_atoi.o ft_bzero.o ft_csd.o ft_errors_list.o ft_isalnum.o\
ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_isspace.o\
ft_itoa.o ft_lstadd.o ft_lstcount.o ft_lstdel.o ft_lstdelone.o\
ft_lstfold.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_lstprint.o\
ft_lstrev.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o\
ft_memdel.o ft_memmove.o ft_memset.o ft_nbrlen.o ft_printf.o ft_putchar.o\
ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o\
ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o\
ft_strcount.o ft_strcpy.o ft_strctrim.o ft_strdel.o ft_strdup.o ft_strequ.o\
ft_strerror.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o\
ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strndup.o\
ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strpos.o ft_strrchr.o ft_strrepeat.o\
ft_strreplace.o ft_strrev.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o\
ft_tolower.o ft_toupper.o get_next_line.o
all : $(NAME)
$(NAME) :
	gcc -c $(CFILES) -Wall -Wextra -Werror
	ar rc $(NAME) $(OFILES)
clean :
	rm -rf $(OFILES)
fclean : clean
	rm -rf $(NAME)
re : fclean all
