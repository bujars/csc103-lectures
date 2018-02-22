COMMON   := -Wall -g
CFLAGS   := $(CFLAGS) $(COMMON)
CXXFLAGS := $(CXXFLAGS) $(COMMON)
CC       := gcc
CXX      := g++

TARGETS  := reverse capacity-test

.PHONY : all
all : $(TARGETS)

$(TARGETS) : % : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY : clean
clean :
	rm -f $(TARGETS)

# vim:ft=make:foldmethod=marker:foldmarker={{{,}}}
