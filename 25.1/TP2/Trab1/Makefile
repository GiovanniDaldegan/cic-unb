all: testa_romanos.cpp romanos.cpp romanos.hpp romanos.o
	g++ -Wall romanos.o testa_romanos.cpp -o testa_romanos
	./testa_romanos

compile: testa_romanos.cpp romanos.cpp romanos.hpp romanos.o
	g++ -std=c++11 -Wall romanos.o testa_romanos.cpp -o testa_romanos

test: testa_romanos
	./testa_romanos

cpplint: testa_romanos.cpp romanos.cpp romanos.hpp
	cpplint --filter=-readability/utf8 --exclude=catch.hpp *.hpp *.cpp

gcov: testa_romanos.cpp romanos.cpp romanos.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c romanos.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage romanos.o testa_romanos.cpp -o testa_romanos
	./testa_romanos
	gcov *.cpp

debug: testa_romanos.cpp romanos.cpp romanos.hpp 
	g++ -std=c++11 -Wall -g -c romanos.cpp
	g++ -std=c++11 -Wall -g romanos.o testa_romanos.cpp -o testa_romanos
	gdb testa_romanos

cppcheck: testa_romanos.cpp romanos.cpp romanos.hpp
	cppcheck --enable=warning romanos.hpp romanos.cpp testa_romanos.cpp

valgrind: testa_romanos
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_romanos

romanos.o: romanos.cpp romanos.hpp
	g++ -std=c++11 -Wall -c romanos.cpp

testa_romanos: testa_romanos.cpp romanos.cpp romanos.hpp romanos.o
	g++ -std=c++11 -Wall romanos.o testa_romanos.cpp -o testa_romanos

clean:
	rm -rf *.o *.exe *.gc* *.rpt testa_romanos
