CXX:= c++

CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

NAME:= tests

SRC:= Account.cpp tests.cpp

OBJ:= $(SRC:.cpp=.o)

TEST_LOG:= 19920104_091532.log

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):	Account.hpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

diff:	$(NAME)
	./$(NAME) | diff - $(TEST_LOG)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: clean $(NAME)

PHONY: all clean fclean re diff
