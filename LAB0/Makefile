CFLAGS = -c

EXECUTABLES = L00 L01 L02 L03 L04 L05

all: $(EXECUTABLES)

L00: L00.o
	$(CXX) L00.o -o L00
L01: L01.o
	$(CXX) L01.o -o L01
L02: L02.o
	$(CXX) L02.o -o L02
L03: L03.o
	$(CXX) L03.o -o L03
L04: L04.o
	$(CXX) L04.o -o L04
L05: L05.o
	$(CXX) L05.o -o L05

L00.o: L00.cpp
	$(CXX) $(CFLAGS) L00.cpp
L01.o: L01.cpp
	$(CXX) $(CFLAGS) L01.cpp
L02.o: L02.cpp
	$(CXX) $(CFLAGS) L02.cpp
L03.o: L03.cpp
	$(CXX) $(CFLAGS) L03.cpp
L04.o: L04.cpp
	$(CXX) $(CFLAGS) L04.cpp
L05.o: L05.cpp
	$(CXX) $(CFLAGS) L05.cpp

clean:
	$(RM) *.o $(EXECUTABLES) core
