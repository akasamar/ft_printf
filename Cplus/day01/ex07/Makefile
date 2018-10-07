#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 22:50:16 by akasamar          #+#    #+#              #
#    Updated: 2018/10/03 22:50:17 by akasamar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = 	replace

SRC =   main.cpp

OBJ = 	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all