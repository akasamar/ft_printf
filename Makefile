# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 11:29:52 by ylisyak           #+#    #+#              #
#    Updated: 2018/03/01 21:20:46 by akasamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
LC = ar rc
START = ./a.out
FG = -Wall -Wextra -Werror
SRC =  ft_printf.c \
	   start_prog.c \
	   tools.c \
	   with_int.c \
	   with_char.c \
	   with_str.c \
	   with_oct.c \
	   with_six.c \
	   ft_hex.c \
	   with_ptr.c \
	   with_unint.c \
	   ft_isdigit.c \
	   ft_putstr.c \
	   ft_putchar.c \
	   ft_strlen.c \
	   with_wchar.c \
	   with_swchar.c \
	   start_prog2.c

HD = .
OBJ =  ft_printf.o \
	   start_prog.o \
	   tools.o \
	   with_int.o \
	   with_char.o \
	   with_str.o \
	   with_oct.o \
	   with_six.o \
	   ft_hex.o \
	   with_ptr.o \
	   with_unint.o \
	   ft_isdigit.o \
	   ft_putstr.o \
	   ft_putchar.o \
	   ft_strlen.o \
	   with_wchar.o \
	   with_swchar.o\
	   start_prog2.o

all: $(NAME)

$(NAME):
	$(CC) $(FG) -c $(SRC) -I $(HD)
	$(LC) $(NAME) $(OBJ)

clean:
	rm -Rf *.o

fclean: clean
	rm -Rf $(NAME)

re: fclean all
