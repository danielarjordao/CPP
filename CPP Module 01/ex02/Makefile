# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 15:07:59 by dramos-j          #+#    #+#              #
#    Updated: 2025/05/01 15:08:00 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOME = brain
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NOME)

$(NOME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NOME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NOME)

re: fclean all
.PHONY: all clean fclean re
