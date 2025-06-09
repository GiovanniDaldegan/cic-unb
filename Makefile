all: testa_velha.c velha.c velha.h velha.o
	g++ -Wall velha.o testa_velha.c -o testa_velha
	./testa_velha

compile: testa_velha.c velha.c velha.h velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.c -o testa_velha

test: testa_velha
	./testa_velha

clint: testa_velha.c velha.c velha.h
	clint --filter=-readability/utf8 --exclude=catch.h *.h *.c

gcov: testa_velha.c velha.c velha.h 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.c
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage velha.o testa_velha.c -o testa_velha
	./testa_velha
	gcov *.c

debug: testa_velha.c velha.c velha.h 
	g++ -std=c++11 -Wall -g -c velha.c
	g++ -std=c++11 -Wall -g velha.o testa_velha.c -o testa_velha
	gdb testa_velha

ccheck: testa_velha.c velha.c velha.h
	ccheck --enable=warning velha.h velha.c testa_velha.c

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_velha

velha.o: velha.c velha.h
	g++ -std=c++11 -Wall -c velha.c

testa_velha: testa_velha.c velha.c velha.h velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.c -o testa_velha

clean:
	rm -rf *.o *.exe *.gc* *.rpt testa_velha
