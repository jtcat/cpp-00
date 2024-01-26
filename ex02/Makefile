CC:= c++

CFLAGS:= -Wall -Wextra -Werror -std=c++98

TEST_LOG:= 19920104_091532.log

tests:	Account.hpp Account.cpp tests.cpp
	$(CC) $(CFLAGS) Account.cpp tests.cpp -o $@

diff:	tests
	./tests | diff - $(TEST_LOG)

