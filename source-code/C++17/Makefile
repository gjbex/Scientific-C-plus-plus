CXX = g++
CXXFLAGS = -std=c++17 -O2 -g -Wall -Wextra -Wpedantic

all: if_init.exe structured_bindings.exe

%.exe: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(wildcard *.o) $(wildcard *.exe)
	$(RM) core $(wildcard core.*)
