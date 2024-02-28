CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic
SRCS := main.cpp longest_path.cpp unit_tests.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := longest_path

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(EXEC)
