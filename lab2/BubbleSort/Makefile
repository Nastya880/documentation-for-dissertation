NAME		= a

SRC			= lab2.cpp

OBJ			= $(SRC:.cpp=.o)

CPP 		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
