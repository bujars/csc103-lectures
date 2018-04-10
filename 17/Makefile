main = morerecursion
CC = g++
CFLAGS = -Wall -O2

$(main) : $(main).cpp
	$(CC) $(CFLAGS) $< -o $(main)

.PHONY : clean
clean :
	rm -f $(main)
