CXX:= c++
CXXFLAGS:= -g -Wall -Wextra -Werror -std=c++98

NAME:= phonebook

HDR:= PhoneBook.hpp Contact.hpp

SRC:= PhoneBook.cpp Contact.cpp PhoneBookApp.cpp

OBJ:= $(SRC:.cpp=.o)

all: $(NAME)

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):	$(OBJ) $(HDR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)
