CXX = g++
CXXFLAGS	= -std=c++11 -Wall

all: shop

test: test

clean:
	rm shop Store.o Item.o TextUI.o

test: test.cpp Store.o Item.o TextUI.o
	$(CXX) $(CXXFLAGS) test.cpp Store.o Item.o TextUI.o -o test

shop: main.cpp Store.o Item.o TextUI.o
	$(CXX) $(CXXFLAGS) main.cpp Store.o Item.o TextUI.o -o shop

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

Store.o: Store.cpp
	$(CXX) $(CXXFLAGS) -c Store.cpp

Item.o: Item.cpp
	$(CXX) $(CXXFLAGS) -c Item.cpp
