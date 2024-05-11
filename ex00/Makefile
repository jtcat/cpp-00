CXX:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

NAME:= megaphone

all: $(NAME)

SRC:= megaphone.cpp

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@

fclean:
	rm -f $(NAME)

re: fclean $(NAME)

PHONY: all fclean re
