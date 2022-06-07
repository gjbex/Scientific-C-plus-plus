CXX = g++
CXXFLAGS = -std=c++20 -O2 -g -Wall -Wextra -Wpedantic
LDLIBS = -lm

all: simple.exe transform_accumulate.exe

%.exe: %.o
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

clean:
	$(RM) *.exe *.o
	$(RM) core core.*
