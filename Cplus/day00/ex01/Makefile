#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 14:51:23 by akasamar          #+#    #+#              #
#    Updated: 2018/10/02 14:51:25 by akasamar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = phonebook

SRC = phonebook.cpp

OBJ = $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

CC = clang++

FLAGS = -Wall -Wextra -Werror

SRCDIR  = ./
OBJDIR  = ./obj/

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
