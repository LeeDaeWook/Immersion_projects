NAME = ex02

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

CC = c++

CFLAGS = -c -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
