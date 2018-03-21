main = set-example
CC = g++
CFLAGS = -Wall -std=c++11

$(main) : $(main).cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY : clean
clean :
	rm -f $(main)
