CXX=g++
CXXFLAGS=-O3 -std=c++17 -Wall -Wextra -Wpedantic

all: depend cellular_automaton.exe

depend: .depend

include .depend

.depend: $(wildcard *.cpp)
	$(CXX) $(CXXFLAGS) -MM $^ -MF $@

cellular_automaton.exe: automaton_runner.o cycle_finder.o main.o
	g++ $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(wildcard *.o) $(wildcard *.exe)
	$(RM) .depend
