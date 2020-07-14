.PHONY: clean

tests: test.o rpsgame.o
	g++ test.o rpsgame.o -o tests

rpsgame.o: rpsgame.cpp rpsgame.hpp
	g++ -c rpsgame.cpp -o rpsgame.o

test.o: doctest.h rpsgame.hpp
	g++ -c test.cpp -o test.o

clean:
	rm ./*.o ./tests
