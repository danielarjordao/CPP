NAME = GlobalBanksters
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = tests.cpp \
		Account.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
