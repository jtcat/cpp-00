CC:= c++
CFLAGS:= -Wall -Wextra -Werror -std=c++98

NAME:= megaphone

all: $(NAME)

SRC:= megaphone.cpp

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

fclean:
	rm -f $(NAME)

re: fclean $(NAME)
