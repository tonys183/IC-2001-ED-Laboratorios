CFLAGS = -c

Main: Main.o
	$(CXX) Main.o -o Main

Main.o: Main.cpp
	$(CXX) $(CFLAGS) Main.cpp

clean:
	$(RM) *.o Main core
