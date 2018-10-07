# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 15:10:54 by ovirchen          #+#    #+#              #
#    Updated: 2018/10/07 15:10:55 by ovirchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SOURCES = main.cpp \
          BulletClass.cpp \
          myGameClass.cpp \
          SpaceShipClass.cpp

SRCS = $(addprefix src/,$(SOURCES))

OBJ = $(SOURCES:.cpp=.o)

HEADERS = includes/BulletClass.hpp \
          includes/myGameClass.hpp \
          includes/rush00.hpp \
          includes/SpaceShipClass.hpp

CC = clang++

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses
	@echo "\033[32mft_retro\033[33m MAKED\033[0m"

$(OBJ): $(SRCS) $(HEADERS)
	$(CC) -c $(SRCS) -I $(HEADERS)

clean:
	rm -f $(OBJ)
	@echo "\033[33mCLEANED\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[33mCLEANED ALL\033[0m"

re: fclean all

.PHONY: all clean fclean re
