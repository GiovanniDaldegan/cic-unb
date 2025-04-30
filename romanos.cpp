#define CATCH_CONFIG_MAIN
#include "romanos.hpp"
#include <iostream>

using namespace std;

int romanos_para_decimal(const char * num_romano) {
    int resultado = 0;
	int count_alg[7] = {0};			// lista de contagem dos algarismos presentes no número. os
									// índices pares contém unidades e os ímpares, símbolos "metade"

	int offset = 0;
	while (*(num_romano + offset) != '\0') {
		switch (*(num_romano + offset)) {
			case int(*"I"):
				resultado++;
				count_alg[6]++;
				break;

			case int(*"V"):
				resultado += 5;
				count_alg[5]++;
				break;

			case int(*"X"):
				resultado += 10;
				count_alg[4]++;
				break;

			case int(*"L"):
				resultado += 50;
				count_alg[3]++;
				break;

			case int(*"C"):
				resultado += 100;
				count_alg[2]++;
				break;

			case int(*"D"):
				resultado += 500;
				count_alg[1]++;
				break;

			case int(*"M"):
				resultado += 1000;
				count_alg[0]++;
				break;

			default:
				return -1;
		}

		for (int i = 0; i < 7; i++) {
			if (i % 2 == 1 && count_alg[i] > 1)		// até 3 unidades
				return -1;
			else if (count_alg[i] > 3)				// até 1 símbolo metade
				return -1;
		}

		offset++;
	}

    return resultado;
}
