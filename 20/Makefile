SOURCES := $(wildcard *.c src/**/*.c *.cpp src/**/*.cpp)

COMMON   := -O2 -Wall -Wformat=2 -march=native -std=c++0x
CXXFLAGS := $(CXXFLAGS) $(COMMON)
CXX      := g++

TARGETS   := ksubsets powerset perms

.PHONY : all
all : $(TARGETS)

# {{{ for debugging
DBGFLAGS := -g -O0
debug : CXXFLAGS += $(DBGFLAGS)
debug : all
.PHONY : debug
# }}}

$(TARGETS) : % : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY : clean
clean :
	rm -f $(TARGETS)

# vim:ft=make:foldmethod=marker:foldmarker={{{,}}}

