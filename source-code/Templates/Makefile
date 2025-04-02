CXX = g++
CXXFLAGS = -O2 -g -Wall -Wextra -std=c++20
LDLIBS = -lm

.PRECIOUS: %.o

APPL = swap.exe sum.exe points.exe print_container_no_range_for.exe fac.exe

all: $(APPL)

%.exe: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(APPL)
