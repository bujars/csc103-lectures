SOURCES := $(wildcard *.c src/**/*.c *.cpp src/**/*.cpp)
OBJECTS := $(SOURCES:.c=.o)
OBJECTS := $(OBJECTS:.cpp=.o)
HEADERS := $(wildcard *.h include/*.h)

# NOTE: remove the -fno-stack-protector to see the 'stack canary'
# protection mechanism in action.
COMMON   := -O0 -Wall -Wformat=2 -std=c++98 -pedantic-errors -fno-stack-protector
CFLAGS   := $(CFLAGS) $(COMMON)
CXXFLAGS := $(CXXFLAGS) $(COMMON)
CC       := gcc
CXX      := g++
LD       := $(CXX)
LDFLAGS  := $(LDFLAGS)
LDADD    :=  # -lrt
INCLUDE  :=  # -I../path/to/headers/
DEFS     :=  # -DLINUX

TARGET   := test

.PHONY : all
all : $(TARGET)

# {{{ for debugging
DBGFLAGS := -g
debug : CFLAGS += $(DBGFLAGS)
debug : CXXFLAGS += $(DBGFLAGS)
debug : all
.PHONY : debug
# }}}

$(TARGET) : $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDADD)

%.s : %.cpp
	$(CXX) $(CXXFLAGS) -S -fverbose-asm $< -o $@

%.o : %.cpp $(HEADERS)
	$(CXX) $(DEFS) $(INCLUDE) $(CXXFLAGS) -c $< -o $@

%.o : %.c $(HEADERS)
	$(CC) $(DEFS) $(INCLUDE) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -f $(TARGET) $(OBJECTS) *.s

# vim:ft=make:foldmethod=marker:foldmarker={{{,}}}

