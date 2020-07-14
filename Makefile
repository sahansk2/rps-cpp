CXX = g++ -pedantic-errors -Werror -Wall -Wextra --std=c++11
.PHONY: clean

tests: test.o rpsgame.o
	$(CXX) test.o rpsgame.o -o tests

rpsgame.o: rpsgame.cpp rpsgame.hpp
	$(CXX) -c rpsgame.cpp -o rpsgame.o

test.o: doctest.h rpsgame.hpp test.cpp
	$(CXX) -c test.cpp -o test.o

clean:
	rm -f ./*.o ./tests
