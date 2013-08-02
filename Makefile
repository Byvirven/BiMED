all : 
	c++ -std=c++11 -o BiMED *.cpp `pkg-config --libs --cflags gtkmm-3.0 gdkmm-3.0 xerces-c` -W -Wall
	
clean :
	rm *~
	rm BiMED
