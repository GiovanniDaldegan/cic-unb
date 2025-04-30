#include "romanos.hpp"
#include <iostream>

using namespace std;

int romanos_para_decimal(const char * num_romano) {

    int resultado = 0;
	char algarismos[] = "MDCLXVI";

	int offset = 0;
	while (*(num_romano + offset) != '\0') {
		if (*(num_romano + offset) == int(*"I")) {
			resultado++;
		}
		else if (*(num_romano + offset) == int(*"V")) {
			resultado += 5;
		}
		else if (*(num_romano + offset) == int(*"X")) {
			resultado += 10;
		}
		else if (*(num_romano + offset) == int(*"L")) {
			resultado += 50;
		}
		else if (*(num_romano + offset) == int(*"C")) {
			resultado += 100;
		}
		else if (*(num_romano + offset) == int(*"D")) {
			resultado += 500;
		}
		else if (*(num_romano + offset) == int(*"M")) {
			resultado += 1000;
		}
		else {
			return -1;
		}

		offset++;
	}

    return resultado;
}
