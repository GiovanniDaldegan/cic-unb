all: testa_velha.cpp velha.c velha.h velha.o
	g++ -Wall velha.o testa_velha.cpp -o testa_velha
	./testa_velha

compile: testa_velha.cpp velha.c velha.h velha.o
	g++ -std=c++20 -Wall velha.o testa_velha.cpp -o testa_velha

test: testa_velha
	./testa_velha

cpplint: testa_velha.cpp velha.c velha.h
	cpplint --filter=-readability/utf8 --exclude=catch.hpp *.h *.c *.hpp *.cpp

cppcheck: testa_velha.cpp velha.c velha.h
	cppcheck --enable=warning --suppressions-list=cppcheck_suppressions.txt velha.h velha.c testa_velha.cpp

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_velha

gcov: testa_velha.cpp velha.c velha.h 
	g++ -std=c++20 -Wall -fprofile-arcs -ftest-coverage -c velha.c
	g++ -std=c++20 -Wall -fprofile-arcs -ftest-coverage velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	gcov *.c

debug: testa_velha.cpp velha.c velha.h 
	g++ -std=c++20 -Wall -g -c velha.c
	g++ -std=c++20 -Wall -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha

velha.o: velha.c velha.h
	g++ -std=c++20 -Wall -c velha.c

testa_velha: testa_velha.cpp velha.c velha.h velha.o
	g++ -std=c++20 -Wall velha.o testa_velha.cpp -o testa_velha

clean:
	rm -rf *.o *.exe *.out *.gc* *.rpt testa_velha
