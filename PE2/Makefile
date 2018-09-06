# PE2 - Eric Oropezaelwood

CXX = g++  # the compiler
CXXFLAGS = -std=c++11 -ggdb -Wall  # flags for the compiler (use c++11 standards, include gdb debug info, turn on all optional warnings)

# Runs for "make all"
all: Point

Point: main.o Point.o
	g++ main.o Point.o -o Point

main.o:
	g++ -c main.cpp
Point.o:
	g++ -c Point.cpp

# runs for "make clean"
clean:
	rm main.o Point.o Point